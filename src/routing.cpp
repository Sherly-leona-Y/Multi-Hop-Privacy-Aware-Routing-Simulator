#include "routing.h"
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

pair<vector<int>, int> Routing::dijkstra(
    const Graph& graph,
    int source,
    int destination
) {
    const int INF = numeric_limits<int>::max();

    int n = graph.getNodes();

    vector<int> distance(n + 1, INF);
    vector<int> parent(n + 1, -1);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int currentDistance = pq.top().first;
        int currentNode = pq.top().second;

        pq.pop();

        if (currentDistance > distance[currentNode]) {
            continue;
        }

        for (const auto& edge : graph.getNeighbors(currentNode)) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distance[currentNode] + weight < distance[neighbor]) {
                distance[neighbor] =
                    distance[currentNode] + weight;

                parent[neighbor] = currentNode;

                pq.push({
                    distance[neighbor],
                    neighbor
                });
            }
        }
    }

    vector<int> path;

    if (distance[destination] == INF) {
        return {path, -1};
    }

    int current = destination;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    return {path, distance[destination]};
}