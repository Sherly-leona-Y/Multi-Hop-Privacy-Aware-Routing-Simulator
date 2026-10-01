#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "graph.h"
#include <vector>

using namespace std;

class Simulator {
public:
    static void simulate(
        const Graph& graph,
        const vector<int>& path,
        int packets
    );
};

#endif