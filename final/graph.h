// graph.h
#pragma once
#include <vector>
#include <unordered_map>
#include <algorithm> // For sorting algorithms like std::sort
#include <iostream>
#include <queue> // For priority_queue data structure
#include <climits> // For INT_MAX constant
#include "graph_node.h"
#include "edge.h"
#include "DSU.h"

class Graph {
    private:
        std::unordered_map<char, GraphNode*> nodes; // Maps node names to node pointers
        std::vector<Edge*> edges; // List of all edges in the graph

    public:
        ~Graph();

        void addNode(char name);

        void addEdge(char sourceName, char destName, int weight);

        void minimumSpanningTree();

        void shortestPath(char start, char end);

        void clearGraph();
};