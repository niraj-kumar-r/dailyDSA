#include <queue>
#include <vector>
#include <bits/stdc++.h>

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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> lo = {{}};
        if (root == nullptr)
        {
            lo.pop_back();
            return lo;
        }
        lo.back().push_back(root->val);
        vector<int> l = {};
        lo.push_back(l);
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        int i = 0;

        while (!q.empty())
        {
            TreeNode *n = q.front();
            q.pop();
            if (n != nullptr)
            {
                q.push(n->left);
                q.push(n->right);
                lo.back().push_back(n->val);
            }
            i++;
            if (i == lo.at(lo.size() - 2).size() * 2)
            {
                vector<int> level = {};
                lo.push_back(level);
                i = 0;
            }
        }
        while (lo.back().empty())
        {
            lo.pop_back();
        }
        return lo;
    }
};

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> lo = s.levelOrder(root);
    for (int i = 0; i < lo.size(); i++)
    {
        for (int j = 0; j < lo[i].size(); j++)
        {
            cout << lo[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}