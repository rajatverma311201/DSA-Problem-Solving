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

// and store the maximum  sum of
// left and right height at every node
int Diameter(Tree *root, int &max_)
{
    if (root == NULL)
        return 0;
    int lh = Diameter(root->left, max_);
    int rh = Diameter(root->right, max_);
    max_ = max(max_, (lh + rh));
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

    int dia = -1;

    cout << "\nDiameter : " << Diameter(root, dia);

    return 0;
}