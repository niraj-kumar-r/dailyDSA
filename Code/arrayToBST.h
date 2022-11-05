//
// Created by Niraj on 05-11-2022.
//

#ifndef DAILYDSA_ARRAYTOBST_H
#define DAILYDSA_ARRAYTOBST_H

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <cmath>

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }

    TreeNode* helper(vector<int>& nums, int start, int end){
        if(start > end){
            return nullptr;
        }
        else if(start == end){
            return new TreeNode(nums[start]);
        }
        int mid = (start + end) / 2;
        TreeNode *a = new TreeNode(nums[mid]);
        a->left = helper(nums, start, mid-1);
        a->right = helper(nums, mid+1, end);
        return a;
    }
};

#endif //DAILYDSA_ARRAYTOBST_H
