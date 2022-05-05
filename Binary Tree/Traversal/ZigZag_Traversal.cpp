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
    queue<Tree *> Q;

    bool flag = true;
    if (root == NULL)
    {
        return traverse;
    }
    Q.push(root);

    while (!Q.empty())
    {
        int n = Q.size();
        vector<int> li(n);
        Tree *x;
        for (int i = 0; i < n; i++)
        {
            x = Q.front();
            Q.pop();

            if (flag == true)
                li[i] = x->data;
            else
                li[n - i - 1] = x->data;

            if (x->left != NULL)
            {
                Q.push(x->left);
            }
            if (x->right != NULL)
            {
                Q.push(x->right);
            }
        }
        flag = !flag;
        if (li.size())
            traverse.push_back(li);
    }
    return traverse;
}
int main()
{
    /*
               5
             /   \
            4     3
             \   / \
              9 2   7
    */
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
                cout << traverse[i][j] << " ,";
        }
        cout << " ]";
    }
    cout << " ]";

    return 0;
}
