#include <iostream>
#include "graph.h" // Include your graph header file

int main() {
    Graph g;
    g.addNode('A');
    g.addNode('B');
    g.addNode('C');
    g.addEdge('A', 'B', 1);
    g.addEdge('B', 'C', 2);
    g.addEdge('A', 'C', 3);

    std::cout << "Minimum Spanning Tree:" << std::endl;
    g.minimumSpanningTree(); // Expected output: A -- B, B -- C (or equivalent) with a cost of 3

    std::cout << "\nShortest Path from A to C:" << std::endl;
    g.shortestPath('A', 'C'); // Expected output: A B C (Cost: 3)

    g.clearGraph();

    // New Graph
    g.addNode('A');
    g.addNode('B');
    g.addNode('C');
    g.addNode('D');
    g.addNode('E');

    g.addEdge('A', 'B', 1);
    g.addEdge('A', 'C', 4);
    g.addEdge('B', 'C', 2);
    g.addEdge('B', 'D', 5);
    g.addEdge('C', 'D', 1);
    g.addEdge('C', 'E', 3);
    g.addEdge('D', 'E', 6);

    std::cout << "Minimum Spanning Tree for the new graph setup:" << std::endl;
    g.minimumSpanningTree(); // Expected Output: Weight of 7

    std::cout << "\nShortest Path from A to E:" << std::endl;
    g.shortestPath('A', 'E'); // Expected Output: Total cost of 6

    g.clearGraph();

    return 0;
}
