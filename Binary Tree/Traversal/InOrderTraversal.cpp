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



// this function recursively finds the inorder
// LEFT, ROOT, RIGHT
void traverse(Tree *root,vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    traverse(root->left, in);
    in.push_back(root->data);
    traverse(root->right, in);
}

// this functions call the traverse function 
// which takes root and a vector by reference 
// and gives the inorder traversal
// this function finally returns the 
// inorder traversal vector 
vector<int> Inorder(Tree *root)
{
    vector<int> in;
    traverse(root, in);
    return in;
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

    vector<int> in = Inorder(root);

    // display the InOrder traversal
    cout << "[ ";
    for (int i = 0; i < in.size(); i++)
    {
        if (i == in.size() - 1)
            cout << in[i];
        else
            cout << in[i] << ", ";
    }
    cout << " ]";

    return 0;
}
