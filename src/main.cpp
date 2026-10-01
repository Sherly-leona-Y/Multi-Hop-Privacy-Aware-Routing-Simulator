#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

#include "graph.h"
#include "routing.h"
#include "privacy.h"
#include "simulator.h"

using namespace std;

int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    cout << "============================================\n";
    cout << "   MULTI-HOP PRIVACY-AWARE ROUTING SIMULATOR\n";
    cout << "============================================\n";

    // Open the network configuration file.
    ifstream inputFile("data/network.txt");

    if (!inputFile) {
        cout << "\nError: Could not open data/network.txt\n";
        cout << "Make sure the program is run from the project folder.\n";
        return 1;
    }

    // Read number of nodes.
    int numberOfNodes;
    inputFile >> numberOfNodes;

    // Create the network.
    Graph network(numberOfNodes);

    // Read network edges.
    int u, v, weight;

    while (inputFile >> u >> v >> weight) {
        network.addEdge(u, v, weight);
    }

    inputFile.close();

    // Display the network.
    network.displayGraph();

    // Define source and destination.
    // Get source and destination from the user.
int source;
int destination;
int packets;

cout << "\nEnter source node (1-" << numberOfNodes << "): ";
cin >> source;

cout << "Enter destination node (1-" << numberOfNodes << "): ";
cin >> destination;

cout << "Enter number of packets to simulate: ";
cin >> packets;

// Validate user input.
if (source < 1 || source > numberOfNodes ||
    destination < 1 || destination > numberOfNodes) {

    cout << "\nError: Invalid source or destination node.\n";
    cout << "Please enter node numbers between 1 and "
         << numberOfNodes << ".\n";

    return 1;
}

if (source == destination) {
    cout << "\nError: Source and destination cannot be the same.\n";
    return 1;
}

if (packets <= 0) {
    cout << "\nError: Number of packets must be greater than 0.\n";
    return 1;
}

    cout << "\nSource Node: " << source << '\n';
    cout << "Destination Node: " << destination << '\n';

    // Find shortest route using Dijkstra.
    auto result =
        Routing::dijkstra(network, source, destination);

    vector<int> path = result.first;
    int totalCost = result.second;

    if (path.empty()) {
        cout << "\nNo route found between source and destination.\n";
        return 0;
    }

    cout << "\n========== ROUTING RESULT ==========\n";

    cout << "Selected Path: ";

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];

        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }

    cout << "\nTotal Routing Cost: "
         << totalCost << '\n';

    cout << "Number of Hops: "
         << path.size() - 1 << '\n';

    // Calculate privacy risk.
    int privacyRisk =
        Privacy::calculatePrivacyRisk(path);

    Privacy::displayPrivacyReport(
        path,
        privacyRisk
    );

    // Define maximum acceptable privacy risk.
    const int MAX_PRIVACY_RISK = 60;

    if (Privacy::isPrivacySafe(
            path,
            MAX_PRIVACY_RISK)) {

        cout << "\nRoute Status: PRIVACY SAFE\n";

        // Simulate packet transmission.
        Simulator::simulate(
    network,
    path,
    packets
);

    } else {

        cout << "\nRoute Status: PRIVACY RISK TOO HIGH\n";
        cout << "Packet simulation cancelled.\n";
    }

    cout << "\nSimulation completed successfully.\n";

    return 0;
}