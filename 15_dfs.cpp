#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

#define N 10005

struct ListNode {
    int data;
    struct ListNode *next;
};

struct graph {
    struct ListNode *head[N];

    graph() {
        for (int i = 0; i < N; i++) {
            head[i] = nullptr;
        }
    }
};

struct edges {
    int src, dest;
};

void show_graph(struct graph *g, int n) {
    for (int i = 0; i < n; i++) {
        struct ListNode *graph_ptr = g->head[i];
        if (graph_ptr != NULL) {
            cout << i << "-->";
        }
        while (graph_ptr != NULL) {
            cout << graph_ptr->data << " ";
            graph_ptr = graph_ptr->next;
        }
        cout << endl;
    }
}

struct graph *create_graph(vector<edges> &arr_edges, int n, int m) {
    struct graph *g = new graph(); // Use `new` instead of `malloc()`

    for (int i = 0; i < m; i++) {
        int u = arr_edges[i].src, v = arr_edges[i].dest;

        // Edge from u->v
        struct ListNode *newNode = new ListNode();
        newNode->data = v;
        newNode->next = g->head[u];
        g->head[u] = newNode;

        // Edge from v->u
        newNode = new ListNode();
        newNode->data = u;
        newNode->next = g->head[v];
        g->head[v] = newNode;
    }

    return g;
}

void dfs_util(struct graph *g, int node, vector<int> &visited) {
    visited[node] = 1;
    cout << node << " ";

    struct ListNode *ptr = g->head[node];
    while (ptr != NULL) {
        if (!visited[ptr->data]) {
            dfs_util(g, ptr->data, visited);
        }
        ptr = ptr->next;
    }
}

void dfs(struct graph *g, int n) {
    vector<int> visited(n, 0);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs_util(g, i, visited);
        }
    }
    cout << endl;
}

int main() {
    int t = 1;
    while (t--) {
        int queries;
        cin >> queries;
        while (queries--) {
            int n, m;
            cin >> n >> m;
            vector<edges> arr_edges(m);

            for (int i = 0; i < m; i++) {
                int u, v;
                cin >> u >> v;
                arr_edges[i].src = u;
                arr_edges[i].dest = v;
            }

            struct graph *g = create_graph(arr_edges, n, m);
            dfs(g, n);

            // Free allocated memory
            delete g;
        }
    }
    return 0;
}
