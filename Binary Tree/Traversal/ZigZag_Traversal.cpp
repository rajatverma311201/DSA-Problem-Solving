#include <iostream>
#include <vector>
#include <queue>
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

vector<vector<int>> zigzagLevelOrder(Tree *root)
{
    vector<vector<int>> traverse;

    if (root == NULL)
    {
        return traverse;
    }

    // we take a queue to push all
    // the elements of a level in it
    queue<Tree *> Q;
    Q.push(root);

    // flag variable indicates the order in which
    // we have to fill the list of that level
    // i.e. from left to right or from right to left
    bool flag = true;
    while (!Q.empty())
    {
        int n = Q.size();
        vector<int> li(n);
        Tree *node;

        // we run a loop for all the elements of a level
        // means all the elements present in the queue
        for (int i = 0; i < n; i++)
        {
            node = Q.front();
            Q.pop();

            // if true then fill the elements from left to right
            if (flag == true)
                li[i] = node->data;

            // if false then fill the elements from right to left
            else
                li[n - i - 1] = node->data;

            // push the child elements of the nodes
            // means the elements at a lower level
            if (node->left != NULL)
            {
                Q.push(node->left);
            }
            if (node->right != NULL)
            {
                Q.push(node->right);
            }
        }
        // reverse the flag indicator after each level
        flag = !flag;
        if (li.size())
            traverse.push_back(li);
    }
    return traverse;
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

    vector<vector<int>> traverse = zigzagLevelOrder(root);

    // display the zig zag level order traversal
    cout << "[ ";
    for (int i = 0; i < traverse.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < traverse[i].size(); j++)
        {
            if (j == traverse[i].size() - 1)
                cout << traverse[i][j];
            else
                cout << traverse[i][j] << ", ";
        }
        cout << " ]";
    }
    cout << " ]";

    return 0;
}
