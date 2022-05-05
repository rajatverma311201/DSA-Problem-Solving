#include <iostream>
#include <vector>

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


// this function recursively finds the preorder
// ROOT, LEFT, RIGHT
void traverse(Tree *root,vector<int> &pre)
{
    if (root == NULL)
    {
        return;
    }
    pre.push_back(root->data);
    traverse(root->left, pre);
    traverse(root->right, pre);
}

// this functions call the traverse function 
// which takes root and a vector by reference 
// and gives the preorder traversal
// this function finally returns the 
// preorder traversal vector 
vector<int> Preorder(Tree *root)
{
    vector<int> pre;
    traverse(root, pre);
    return pre;
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

vector<int> pre = Preorder(root);

    // display the PreOrder traversal
    cout << "[ ";
    for (int i = 0; i < pre.size(); i++)
    {
        if (i == pre.size() - 1)
            cout << pre[i];
        else
            cout << pre[i] << ", ";
    }
    cout << " ]";

    return 0;
}
