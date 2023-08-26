#include "graph.hpp"

void graph::initialize() {
    std::ifstream fin("data.txt");
    if (!fin.is_open()) {
        std::cout << "Error opening file !";
        return ;
    }
    fin >> n;
    adj = new int*[n];
    for (int i = 0 ; i < n ; i++) {
        adj[i] = new int[n];
        for (int j = 0 ; j < n ; j++) {
            fin >> adj[i][j];
        }
    }
    fin.close();
}

void graph::DFS_traversal(int start) {
    bool* marked = new bool[n];
    for (int i = 0 ; i < n ; i++) marked[i] = false;
    std::stack<int> next;
    next.push(start);

    while (!next.empty()) {
        int cur = next.top();
        next.pop();
        if (marked[cur]) continue ;
        marked[cur] = true;
        std::cout << cur << " ";
        for (int i = n - 1 ; i >= 0 ; i--) {
            if (adj[cur][i] > 0 && !marked[i]) {
                next.push(i);
            }
        }
    }
    delete[] marked;
}

void graph::BFS_traversal(int start) {
    bool* marked = new bool[n];
    for (int i = 0 ; i < n ; i++) marked[i] = false;
    std::queue<int> next;
    next.push(start);

    while (!next.empty()) {
        int cur = next.front();
        next.pop();
        if (marked[cur]) continue ;
        marked[cur] = true;
        std::cout << cur << " ";
        for (int i = 0 ; i < n ; i++) {
            if (adj[cur][i] > 0 && !marked[i]) {
                next.push(i);
            }
        }
    }
}

void graph::Dijkstra(int source) {
    int* distances = new int[n];
    for (int i = 0 ; i < n ; i++) distances[i] = INT_MAX;
    bool* marked = new bool[n];
    for (int i = 0 ; i < n ; i++) marked[i] = false;

    distances[source] = 0;

    std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > pq;
    pq.push({0, source});

    while (!pq.empty()) {
        while (marked[pq.top().second]) pq.pop();
        int cur = pq.top().second;
        pq.pop();
        marked[cur] = true;
        for (int i = 0 ; i < n ; i++) {
            if (adj[cur][i] > 0 && !marked[i] && distances[cur] + adj[cur][i] < distances[i]) {
                distances[i] = distances[cur] + adj[cur][i];
                pq.push({distances[i], i});
            }
        }
    }

    std::cout << "The shortest path from vertex " << source << " to\n";
    for (int i = 0 ; i < n ; i++) {
        std::cout << "vertex " << i << " : " << distances[i] << "\n";
    }
}