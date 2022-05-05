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



// this function recursively finds the postorder
// LEFT, RIGHT, ROOT
void traverse(Tree *root,vector<int> &post)
{
    if (root == NULL)
    {
        return;
    }
    traverse(root->left, post);
    traverse(root->right, post);
    post.push_back(root->data);
}

// this functions call the traverse function 
// which takes root and a vector by reference 
// and gives the postorder traversal
// this function finally returns the 
// postorder traversal vector 
vector<int> Postorder(Tree *root)
{
    vector<int> post;
    traverse(root, post);
    return post;
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

    vector<int> post = Postorder(root);

    // display the PostOrder traversal
    cout << "[ ";
    for (int i = 0; i < post.size(); i++)
    {
        if (i == post.size() - 1)
            cout << post[i];
        else
            cout << post[i] << ", ";
    }
    cout << " ]";

    return 0;
}
