#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Tree
{
public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// topView function to return the top view
vector<int> topView(Tree *root)
{
    // we are doing level order
    // traversal to get the
    // top view elements from left to right
    vector<int> view;
    if (root == NULL)
    {
        return view;
    }

    // map to store unique keys,
    // keys will be vertical lines
    // on which a node is present
    // only the topmost element of a vertical line
    // will be present in the top view
    map<int, int> mpp;

    // queue will contain the elements
    // along with the vertical line on
    // which they are present
    queue<pair<Tree *, int>> Q;

    int line = 0;
    Q.push(make_pair(root, line));
    while (!Q.empty())
    {
        int n = Q.size();
        pair<Tree *, int> p;
        for (int i = 0; i < n; i++)
        {
            p = Q.front();
            Tree *node = p.first;
            Q.pop();
            line = p.second;
            // take the front element of the queue
            // and check if its line is already present
            // in the map,if yes then do nothing
            // if no then insert the element
            // along with the line
            if (mpp.find(line) == mpp.end())
            {
                mpp[line] = node->data;
            }
            // insert the right child with
            // line+1 from the parent node
            if (node->right)
            {
                Q.push(make_pair(node->right, line + 1));
            }
            // insert the left child with
            // line-1 from the parent node
            if (node->left)
            {
                Q.push(make_pair(node->left, line - 1));
            }
        }
    }
    // now copy the elements from the map,
    // which contains the top view elements
    // and store it in vector
    for (auto i = mpp.begin(); i != mpp.end(); i++)
    {
        view.push_back(i->second);
    }
    return view;
}

int main()
{

    //         5
    //       /   \
    //      4     3
    //       \   / \
    //        9 2   7

    Tree *root = new Tree(5);
    root->left = new Tree(4);
    root->left->right = new Tree(9);
    root->right = new Tree(3);
    root->right->left = new Tree(2);
    root->right->right = new Tree(7);

    vector<int> view = topView(root);

    // display the zig zag level order traversal
    cout << "[ ";
    for (int i = 0; i < view.size(); i++)
    {
        if (i == view.size() - 1)
            cout << view[i];
        else
            cout << view[i] << " ,";
    }
    cout << " ]";

    return 0;
}
