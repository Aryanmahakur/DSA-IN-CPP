#include <iostream>
#include <vector>
using namespace std;
/*
// ======== Adjacency Matrix ==========
void runAdjacencyMatrix() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;

    cout << "Enter number of edges: ";
    cin >> e;

    // Create a v x v matrix initialized with 0
    vector<vector<int>> adj(v, vector<int>(v, 0));
   // vector<vector<int>> adj(v);

    int u, w;
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> u >> w;
        adj[u][w] = 1;
        adj[w][u] = 1; // Because it's an undirected graph
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// ======== Adjacency List ==========
vector<vector<int>> createAdjacencyList(int V, int E, vector<pair<int, int>> edges) {
    vector<vector<int>> adjList(V);
    for (int i = 0; i < E; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // because undirected
    }
    return adjList;
}

void runAdjacencyList() {
    int V = 5; // Number of vertices
    int E = 4; // Number of edges

    // Edges of the graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 4},
        {1, 2},
        {1, 3}
    };

    vector<vector<int>> adjList = createAdjacencyList(V, E, edges);

    // Print adjacency list
    cout << "Adjacency List:\n";
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

// ======== Main Function ==========
int main() {
    cout << "Choose graph representation:\n";
    cout << "1. Adjacency Matrix\n";
    cout << "2. Adjacency List\n";
    int choice;
    cin >> choice;

    if (choice == 1) {
        runAdjacencyMatrix();
    } else if (choice == 2) {
        runAdjacencyList();
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}*/
/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        // Traverse all adjacent vertices
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);       // Adjacency list
    vector<bool> visited(V, false);   // Visited array

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;

        // Add edge both ways for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "BFS traversal starting from vertex 0: ";
    bfs(0, adj, visited);

    return 0;
}
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to perform DFS traversal (iterative)
void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;

            // Push neighbors in reverse order to visit them in correct order
            for (int i = adj[node].size() - 1; i >= 0; --i) {
                int neighbor = adj[node][i];
                if (!visited[neighbor]) {
                    st.push(neighbor);
                }
            }
        }
    }
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);       // Adjacency list
    vector<bool> visited(V, false);   // Visited array

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;

        // Undirected edge
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << "Iterative DFS starting from vertex 0: ";
    dfs(0, adj, visited);

    return 0;
}
