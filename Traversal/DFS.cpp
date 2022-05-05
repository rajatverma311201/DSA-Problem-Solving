#include <iostream>
#include <vector>
using namespace std;

// defining all the required functions
void display(vector<int> traversal);
void dfs(int i, vector<int> &traversal, vector<bool> &vis, vector<int> adj[]);
vector<int> graphTraversal(int V, vector<int> adj[]);

// dfs function
void dfs(int node, vector<int> &traversal, vector<bool> &vis, vector<int> adj[])
{
    vis[node] = true;
    traversal.push_back(node);

    // loop to call the dfs again for
    // the node which is not yet visited
    for (auto it : adj[node])
    {
        // if the node in the list is not yet visited,
        // call the dfs for that node
        if (!vis[it])
        {
            dfs(it, traversal, vis, adj);
        }
    }
}

// graph traversal function which call the dfs function
vector<int> graphTraversal(int V, vector<int> adj[])
{
    vector<int> traversal;
    vector<bool> vis(V + 1, false);
    // if node starts from 1 then i from 1
    for (int i = 1; i < V; i++)
    {
        // do dfs for each node which is not yet visited
        if (!vis[i])
        {
            // call the dfs function which will perform
            // the dfs for the current passed node
            dfs(i, traversal, vis, adj);
        }
    }
    return traversal;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("outputDFS.txt", "w", stdout);
#endif

    int n; // n stores no. of nodes
    int m; // m stores edges b/w nodes
    cin >> n >> m;

    // if node starts from 1
    // creating adjaceny list
    vector<int> adj[n + 1];
    while (m--)
    {
        // u and v are 2 nodes connected by a edge
        int u, v;
        cin >> u >> v;
        // for UNDIRECTED Graph insert both relations
        // means (u->v)and also (v->u)
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> traversal = graphTraversal(n, adj);

    // display the dfs traversal
    cout << "DFS : ";
    display(traversal);

    return 0;
}

void display(vector<int> trav)
{
    for (int i = 0; i < trav.size(); i++)
    {
        cout << trav[i] << "  ";
    }
    cout << endl;
}