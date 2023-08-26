#include "graph.hpp" 

int main() {
    graph G;
    G.initialize();
    std::cout << "The BFS traversal : "; G.BFS_traversal(0);
    return 0;
}