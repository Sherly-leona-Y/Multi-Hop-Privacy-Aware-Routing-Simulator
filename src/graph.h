#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <utility>

using namespace std;

class Graph {
private:
    int nodes;
    vector<vector<pair<int, int>>> adjacencyList;

public:
    Graph(int n);

    void addEdge(int u, int v, int weight);

    void displayGraph() const;

    int getNodes() const;

    const vector<pair<int, int>>& getNeighbors(int node) const;
};

#endif