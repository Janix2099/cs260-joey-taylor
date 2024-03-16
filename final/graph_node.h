// graph_node.h

#pragma once

#include <vector>
#include "edge.h"

struct Edge;

struct GraphNode {
    char name;
    std::vector<Edge *> neighbors;
};