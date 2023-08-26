#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

class graph {
    private :
        int n;
        int** adj;
    public :
        void initialize();
        void DFS_traversal(int start);
        void BFS_traversal(int start);
        void Dijkstra(int source);
};