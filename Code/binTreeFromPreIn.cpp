#include <iostream>
#include <vector>
#include <algorithm>

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
    // TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    // {
    //     if (preorder.size() == 0)
    //     {
    //         return nullptr;
    //     }
    //     else if (preorder.size() == 1)
    //     {
    //         return new TreeNode(preorder[0]);
    //     }
    //     vector<int>::iterator it;
    //     it = find(inorder.begin(), inorder.end(), preorder[0]);
    //     TreeNode *root = new TreeNode(preorder[0]);
    //     int p = it - inorder.begin();
    //     vector<int> leftPre = vector<int>(preorder.begin() + 1, preorder.begin() + p + 1);
    //     vector<int> leftIn = vector<int>(inorder.begin(), it);
    //     root->left = buildTree(leftPre, leftIn);
    //     vector<int> rightPre = vector<int>(preorder.begin() + p + 1, preorder.end());
    //     vector<int> rightIn = vector<int>(it + 1, inorder.end());
    //     root->right = buildTree(rightPre, rightIn);
    //     return root;
    // }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildEff(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode *buildEff(vector<int> &preorder, int ps, int pe, vector<int> &inorder, int is, int ie)
    {
        if (ps - pe == 0)
        {
            return nullptr;
        }
        else if (pe - ps == 1)
        {
            return new TreeNode(preorder[ps]);
        }
        auto it = find(inorder.begin() + is, inorder.begin() + ie, preorder[ps]);
        TreeNode *root = new TreeNode(preorder[ps]);
        int p = it - (inorder.begin() + is);
        root->left = buildEff(preorder, ps + 1, ps + p + 1, inorder, is, is + p);
        root->right = buildEff(preorder, ps + p + 1, pe, inorder, is + p + 1, ie);
        return root;
    }
};

int main()
{
    vector<int> pre = {1, 2};
    vector<int> in = {2, 1};
    Solution s;
    TreeNode *root = s.buildTree(pre, in);
    return 0;
}