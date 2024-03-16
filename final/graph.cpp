#include "graph.h"

// Destructor
Graph::~Graph() {
    clearGraph();
}

// Function to add a node to the graph
void Graph::addNode(char name) {
    // Check if node doesn't already exist
    if (nodes.find(name) == nodes.end()) {
        GraphNode* newNode = new GraphNode{name};
        nodes[name] = newNode;
    }
}

// Function to add an edge between two nodes
void Graph::addEdge(char sourceName, char destName, int weight) {
    // Check if both nodes exist
    if (nodes.find(sourceName) != nodes.end() && nodes.find(destName) != nodes.end()) {
        Edge* newEdge = new Edge{weight, nodes[sourceName], nodes[destName]};
        edges.push_back(newEdge);
        // Link the edge to both nodes for undirected graph
        nodes[sourceName]->neighbors.push_back(newEdge);
        nodes[destName]->neighbors.push_back(newEdge);
    }
}

// Computes the minimum spanning tree (MST) of the graph
void Graph::minimumSpanningTree() {
    // Sort all edges by weight to consider the smallest edges first
    std::sort(edges.begin(), edges.end(), [](const Edge* a, const Edge* b) {
        return a->weight < b->weight;
    });

    DSU s(nodes.size()); // Disjoint set for tracking connected components
    int ans = 0; // To store the total weight of the MST
    std::cout << "Following are the edges in the constructed MST\n";

    // Iterate through sorted edges
    for (Edge* edge : edges) {
        int w = edge->weight;
        char x = edge->source->name;
        char y = edge->destination->name;

        // If adding the edge doesn't form a cycle
        if (s.find(x - 'A') != s.find(y - 'A')) {
            s.unite(x - 'A', y - 'A'); // Join the two sets
            ans += w;
            std::cout << x << " -- " << y << " == " << w << std::endl;
        }
    }
    std::cout << "Minimum Cost Spanning Tree: " << ans << std::endl;
}

// Finds the shortest path from start node to end node
void Graph::shortestPath(char start, char end) {
    // Priority queue for Dijkstra's algorithm, smallest distances first
    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>, std::greater<std::pair<int, char>>> pq;
    std::unordered_map<char, int> dist;
    std::unordered_map<char, char> parent;

    // Initialize all distances to infinity
    for (const auto& pair : nodes) {
        dist[pair.first] = INT_MAX;
    }

    // Start node distance to itself is 0
    dist[start] = 0;
    pq.push({0, start});

    // While there are nodes to process
    while (!pq.empty()) {
        char u = pq.top().second; // Node with smallest distance
        pq.pop(); // Remove it from queue

        // Check all neighbors of u
        for (Edge* edge : nodes[u]->neighbors) {
            char v = edge->destination->name; // Neighbor
            int weight = edge->weight; // Weight of edge to neighbor
            // If there's a shorter path to v through u
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight; // Update distance to v
                parent[v] = u; // Update v's parent to u
                pq.push({dist[v], v}); // Add v to priority queue
            }
        }
    }

    // Print the shortest path
    std::cout << "Shortest Path from " << start << " to " << end << ": ";
    char current = end;
    std::vector<char> path;
    while (current != start) {
        path.push_back(current); // Build path backwards from end to start
        current = parent[current]; // Move to parent of current
    }
    path.push_back(start);
    std::reverse(path.begin(), path.end()); // Reverse path to correct order
    for (char vertex : path) { // Print path
        std::cout << vertex << " ";
    }
    std::cout << "(Cost: " << dist[end] << ")" << std::endl; // Print path cost
}

// Clears the graph for new operations
void Graph::clearGraph() {
    for (auto& pair : nodes) {
        delete pair.second;
    }
    nodes.clear();

    for (Edge* edge : edges) {
        delete edge;
    }
    edges.clear();
}
