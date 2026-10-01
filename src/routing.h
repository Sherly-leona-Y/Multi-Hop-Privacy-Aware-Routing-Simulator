#ifndef ROUTING_H
#define ROUTING_H

#include "graph.h"
#include <vector>
#include <utility>

using namespace std;

class Routing {
public:
    static pair<vector<int>, int> dijkstra(
        const Graph& graph,
        int source,
        int destination
    );
};

#endif