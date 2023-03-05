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
        vector<int> a, b, c;
        if (!root)
        {
            return a;
        }
        a.push_back(root->val);
        b = rightSideView(root->left);
        c = rightSideView(root->right);
        a.insert(a.end(), c.begin(), c.end());
        int d = c.size() - b.size();
        if (d > 0)
        {
            a.insert(a.end(), b.begin() + (b.size() - d), b.end());
        }
        return a;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);
    Solution s;
    vector<int> a = s.rightSideView(root);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}