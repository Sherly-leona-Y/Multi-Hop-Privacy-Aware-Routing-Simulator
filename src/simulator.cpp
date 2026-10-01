#include "simulator.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void Simulator::simulate(
    const Graph& graph,
    const vector<int>& path,
    int packets
) {
    if (path.empty()) {
        cout << "\nSimulation cannot start: no valid route.\n";
        return;
    }

    cout << "\n========== PACKET SIMULATION ==========\n";

    cout << "Route: ";

    for (size_t i = 0; i < path.size(); i++) {
        cout << path[i];

        if (i != path.size() - 1) {
            cout << " -> ";
        }
    }

    cout << "\nPackets generated: " << packets << '\n';

    int delivered = 0;
    int dropped = 0;

    for (int packet = 1; packet <= packets; packet++) {

        bool success = true;

        /*
            Each hop has a small probability of
            packet loss in our simulation.
        */
        for (size_t i = 0; i < path.size() - 1; i++) {

            int randomValue = rand() % 100;

            if (randomValue < 10) {
                success = false;
                break;
            }
        }

        if (success) {
            delivered++;

            cout << "Packet " << packet
                 << ": DELIVERED\n";
        }
        else {
            dropped++;

            cout << "Packet " << packet
                 << ": DROPPED\n";
        }
    }

    double deliveryRate =
        (static_cast<double>(delivered) / packets) * 100.0;

    cout << "\n---------- Simulation Results ----------\n";
    cout << "Packets Sent: " << packets << '\n';
    cout << "Packets Delivered: " << delivered << '\n';
    cout << "Packets Dropped: " << dropped << '\n';

    cout << "Delivery Rate: "
         << deliveryRate << "%\n";

    cout << "Number of Hops: "
         << path.size() - 1 << '\n';

    cout << "========================================\n";
}