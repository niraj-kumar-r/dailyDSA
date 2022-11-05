//
// Created by Niraj on 05-11-2022.
//

#ifndef DAILYDSA_BINARYTREETRAVERSAL_H
#define DAILYDSA_BINARYTREETRAVERSAL_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BinaryTreeTraversal {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> inorder;
        if (root == nullptr) {
            return inorder;
        } else if (root->left == nullptr && root->right == nullptr) {
            inorder.push_back(root->val);
            return inorder;
        } else {
            vector<int> l = inorderTraversal(root->left);
            vector<int> r = inorderTraversal(root->right);
            inorder.insert(inorder.end(), l.begin(), l.end());
            inorder.push_back(root->val);
            inorder.insert(inorder.end(), r.begin(), r.end());
            return inorder;
        }
    }

};


#endif //DAILYDSA_BINARYTREETRAVERSAL_H
