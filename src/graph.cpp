#include "graph.h"
#include <iostream>

using namespace std;

Graph::Graph(int n) {
    nodes = n;
    adjacencyList.resize(nodes + 1);
}

void Graph::addEdge(int u, int v, int weight) {
    adjacencyList[u].push_back({v, weight});
    adjacencyList[v].push_back({u, weight});
}

void Graph::displayGraph() const {
    cout << "\nNetwork Topology:\n";

    for (int i = 1; i <= nodes; i++) {
        cout << "Node " << i << " -> ";

        for (const auto& edge : adjacencyList[i]) {
            cout << "(" << edge.first
                 << ", cost=" << edge.second << ") ";
        }

        cout << '\n';
    }
}

int Graph::getNodes() const {
    return nodes;
}

const vector<pair<int, int>>& Graph::getNeighbors(int node) const {
    return adjacencyList[node];
}