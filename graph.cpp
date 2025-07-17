#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adjmat(v, vector<int>(v, 0));

    for (int i = 0; i < e; i++) {
        int u, vtx;
        cin >> u >> vtx;
        adjmat[u][vtx] = 1;
        adjmat[vtx][u] = 1; // Since the graph is undirected
    }

    // Print the adjacency matrix
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int v = 5; // Number of vertices
    int e = 5; // Number of edges

    vector<vector<int>> adj(v); // adjacency list

    vector<pair<int, int>> edgeList = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 4}
    };

    // Build adjacency list
    for (auto a : edgeList) {
        int u = a.first;
        int v = a.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected
    }

    // Print adjacency list
    for (int i = 0; i < v; i++) {
        cout << "Node " << i << ": ";
        for (int n : adj[i]) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS Function
void bfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int v = 5; // number of vertices
    vector<vector<int>> adj(v);

    // Define undirected edges
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 4}
    };

    // Build adjacency list
    for (auto [u, vtx] : edges) {
        adj[u].push_back(vtx);
        adj[vtx].push_back(u); // because it's undirected
    }

    vector<bool> visited(v, false);

    // Call BFS from node 0
    cout << "BFS traversal starting from node 0:\n";
    bfs(0, adj, visited);

    return 0;
}#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int node = st.top();
        st.pop();
        cout << node << " ";

        // Push neighbors in reverse order to maintain order
        for (int i = adj[node].size() - 1; i >= 0; i--) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                st.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int v = 5;
    vector<vector<int>> adj(v);

    // Sample undirected graph
    vector<pair<int, int>> edges = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 4}
    };

    // Build adjacency list
    for (auto [u, vtx] : edges) {
        adj[u].push_back(vtx);
        adj[vtx].push_back(u); // undirected
    }

    vector<bool> visited(v, false);

    // Call DFS
    cout << "DFS traversal starting from node 0:\n";
    dfs(0, adj, visited);

    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
   visited[node]=true;
   cout<<node<<endl;
   for (int n : adj[node])
   {
    int a =adj[n];
    if(!visited[n]){
     dfs(n.adj,viste)
    }
    /* code */
   }
   

int main() {
    int v = 5; // Total number of nodes (0 to 4)

    vector<pair<int, int>> edgeList = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 4}
    };

    vector<vector<int>> adj(v); // Adjacency list

    // Build the adjacency list from edgeList
    for (auto edge : edgeList) {
        int u = edge.first;
        int v = edge.second;
        adj[u].push_back(v);
        adj[v].push_back(u); // Because it's an undirected graph
    }

    vector<bool> visited(v, false);

    cout << "DFS traversal from node 0:\n";
    dfs(0, adj, visited);

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;

// DFS function
void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";  // part of the same component

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int v = 5; // number of vertices

    // Edge list
    vector<pair<int, int>> edge = {
        {0, 1},
        {0, 2},
        {1, 3},
        {2, 4},
        {3, 4}
    };

    // Create adjacency list
    vector<vector<int>> adj(v);
    for (auto n : edge) {
        int u = n.first; // FIXED: should be n.first, not edge.first
        int v = n.second; // FIXED: should be n.second
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph
    }

    vector<bool> visited(v, false); // FIXED: spelling corrected from visted

    int components = 0;
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            cout << "Component " << components + 1 << ": ";
            dfs(i, adj, visited);
            cout << "\n";
            components++;
        }
    }

    cout << "Total Connected Components = " << components << "\n";

    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
#include <iostream>
#include <vector>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    int rows = grid.size();
    int cols = grid[0].size();

    if (i < 0 || j < 0 || i >= rows || j >= cols ||
        grid[i][j] == '0' || visited[i][j]) {
        return;
    }

    visited[i][j] = true;

    dfs(i + 1, j, grid, visited);
    dfs(i - 1, j, grid, visited);
    dfs(i, j + 1, grid, visited);
    dfs(i, j - 1, grid, visited);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    int count = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                dfs(i, j, grid, visited);
                count++;
            }
        }
    }

    return count;
}aaaa

int main() {
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    cout << "Number of Islands: " << numIslands(grid) << endl;
    return 0;
}

