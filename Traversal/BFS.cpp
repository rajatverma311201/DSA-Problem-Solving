#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// defining all the required functions
void display(vector<int> traversal);
void bfs(int i, vector<int> &traversal, vector<bool> &vis, vector<int> adj[]);
vector<int> graphTraversal(int V, vector<int> adj[]);

// bfs function
void bfs(int i, vector<int> &traversal, vector<bool> &vis, vector<int> adj[])
{
    queue<int> Q;

    // doing bfs for ith node
    vis[i] = true;
    Q.push(i);
    while (!Q.empty())
    {
        // take out the current front node from the queue
        int node = Q.front();
        Q.pop();

        // add the node in traversal array
        traversal.push_back(node);

        // loop for all the adjacent elements(breadth)
        // in the list of current node;
        for (auto it : adj[node])
        {
            // if the node in the list is not yet visited,
            // mark visited and then push in the queue
            if (!vis[it])
            {
                vis[it] = true;
                Q.push(it);
            }
        }
    }
}

// graph traversal function which call the bfs function
vector<int> graphTraversal(int V, vector<int> adj[])
{
    vector<int> traversal;
    vector<bool> vis(V + 1, false);
    // if node starts from 1 then i from 1
    for (int i = 1; i < V; i++)
    {
        // do bfs for each node which is not yet visited
        if (!vis[i])
        {
            // call the bfs function which will perform
            // the bfs for the current passed node
            bfs(i, traversal, vis, adj);
        }
    }
    return traversal;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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

    // display the bfs traversal
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