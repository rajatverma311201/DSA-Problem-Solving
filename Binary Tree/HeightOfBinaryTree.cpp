#include <iostream>
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

// see the left and right height of the subtree
// and then return the max of the two
int Height(Tree *root)
{
    if (root == NULL)
        return 0;
    int lh = Height(root->left);
    int rh = Height(root->right);
    return max(lh, rh) + 1;
}

int main()
{
    Tree *root = new Tree(5);
    root->left = new Tree(4);
    root->left->right = new Tree(9);
    root->right = new Tree(3);
    root->right->left = new Tree(2);
    root->right->right = new Tree(7);

    cout << "\nHeight : " << Height(root);

    return 0;
}