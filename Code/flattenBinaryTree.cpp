#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void flatten(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        flatten(root->left);
        flatten(root->right);
        TreeNode *l = root->left;
        if (!l)
        {
            return;
        }
        while (l->right)
        {
            l = l->right;
        }
        l->right = root->right;
        root->right = root->left;
        root->left = nullptr;
    }
};