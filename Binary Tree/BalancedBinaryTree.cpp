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

// check for every node,
// if absolute difference of height between 
// right and left subtree is more than 1 then 
// return -1 else return height
int Balanced(Tree *root)
{
    if (root == NULL)
        return 0;
    int lh = Balanced(root->left);
    if (lh == -1)
        return -1;
    int rh = Balanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
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

    cout << "\nBalanced : " << ((Balanced(root) != -1) ? "YES" : "NO");

    return 0;
}
