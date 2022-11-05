//
// Created by Niraj on 05-11-2022.
//

#ifndef DAILYDSA_SYMMETRIC_P101_H
#define DAILYDSA_SYMMETRIC_P101_H

//
// Created by Niraj on 05-11-2022.
//

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root->left, root->right);
    }

    bool isMirror(TreeNode *l, TreeNode *r){
        if(l==nullptr || r==nullptr){
            return l==r;
        }
        else{
            return (isMirror(l->left,r->right) && isMirror(l->right, r->left) && l->val == r->val);
        }
    }
};


#endif //DAILYDSA_SYMMETRIC_P101_H
