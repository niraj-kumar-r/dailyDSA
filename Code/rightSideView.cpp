#include <iostream>
#include <vector>

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
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> a;
        if (!root)
        {
            return a;
        }
        a.push_back(root->val);
        do
        {
            if (!root->right)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
            if (!root)
            {
                break;
            }
            a.push_back(root->val);

        } while (root->right);

        return a;
    }
};