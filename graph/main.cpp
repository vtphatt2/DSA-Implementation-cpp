#include "graph.hpp" 

int main() {
    graph G;
    G.initialize();
    std::cout << G.costMST();
    return 0;
}