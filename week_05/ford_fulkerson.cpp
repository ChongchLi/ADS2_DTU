#include <bits/stdc++.h>

using namespace std;

vector<int> get_path(uint16_t** graph, int n, int start, int end) {
    vector<int> path;
    bool* visited = new bool[n];
    int* parent = new int[n];
    stack<int> stack;
    int v;
    bool found = false;

    stack.push(start);
    for (int i = 0; i < n; i++) visited[i] = false;
    visited[start] = true;

    while (!stack.empty()) {
        v = stack.top(); stack.pop();
        if (v == end) {
            found = true;
            break;
        }

        for (int i = 0; i < n; i++) {
            if (graph[v][i] > 0 and !visited[i]) {
                stack.push(i);
                visited[i] = true;
                parent[i] = v;
            }
        }
    }

    if (found) {
        v = end;
        path.push_back(v);
        while (v != start) {
            v = parent[v];
            path.push_back(v);
        }
        reverse(path.begin(), path.end());
    }

    delete[] visited;
    delete[] parent;
    return path;
}

int get_bottleneck(uint16_t** graph, vector<int> path) {
    int in_node, out_node, capacity;
    int bottleneck = graph[path[0]][path[1]];

    for (int i = 1; i < path.size() - 1; i++) {
        in_node = path[i];
        out_node = path[i + 1];
        capacity = graph[in_node][out_node];
        if (capacity < bottleneck) bottleneck = capacity;
    }

    return bottleneck;
}

void augment(uint16_t** graph, vector<int> path) {
    int in_node, out_node;
    int bottleneck = get_bottleneck(graph, path);

    for (int i = 0; i < path.size() - 1; i++) {
        in_node = path[i];
        out_node = path[i + 1];
        graph[in_node][out_node] -= bottleneck;
        graph[out_node][in_node] += bottleneck;
    }
}

int max_flow(uint16_t** res_graph, uint16_t** graph, int n, int start, int end) {
    vector<int> path;
    int max_flow = 0;

    while ((path = get_path(res_graph, n, start, end)).size() > 0)
        augment(res_graph, path);

    for (int i = 0; i < n; i++)
        if (graph[i][start] == 0) max_flow += res_graph[i][start];

    return max_flow;
}