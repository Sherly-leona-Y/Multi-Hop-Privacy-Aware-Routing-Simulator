# Multi-Hop Privacy-Aware Routing Simulator

A Computer Networks project that simulates multi-hop packet routing while considering routing cost, privacy risk, and packet delivery performance.

---

## 📌 Overview

The Multi-Hop Privacy-Aware Routing Simulator models a computer network as a weighted graph in which nodes represent network devices and edges represent communication links.

The simulator:

1. Loads a network topology from a configuration file.
2. Accepts a source node, destination node, and number of packets from the user.
3. Uses Dijkstra's algorithm to determine a minimum-cost route.
4. Evaluates the selected route using a simple privacy-risk model.
5. Simulates packet transmission across the selected multi-hop route.
6. Reports packet delivery, packet loss, delivery rate, routing cost, and number of hops.

The privacy model used in this project is an educational simulation metric and does not represent a real-world anonymity or cryptographic privacy guarantee.

---

## 🎯 Objectives

- Understand graph-based network routing.
- Implement Dijkstra's shortest-path algorithm.
- Simulate multi-hop communication between network nodes.
- Introduce a simple privacy-risk evaluation mechanism.
- Simulate packet delivery and packet loss.
- Measure basic network performance metrics.
- Demonstrate concepts from Computer Networks through a practical simulator.

---

## ✨ Features

- Weighted network topology
- Multi-hop routing
- Dijkstra's shortest-path algorithm
- User-defined source and destination
- User-defined packet count
- Privacy-risk evaluation
- Privacy-safe route checking
- Packet delivery simulation
- Packet drop simulation
- Delivery-rate calculation
- Number-of-hops calculation
- Routing-cost calculation
- External network configuration through `network.txt`

---

## 🧠 Algorithms and Concepts

### 1. Graph Representation

The network is represented using an adjacency-list-based weighted graph.

Each network connection contains:

- Source node
- Destination node
- Link cost

Example:

```text
1 2 4