//
// Created by admin on 2023/5/19.
//
//偷父不能偷子
//        result[0],result[1]分别为不偷和偷，分别算val2不偷(父节点)的值和val1偷的值
//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
private:
    auto robTree(TreeNode *cur) -> vector<int>{
        if (cur == nullptr) return vector<int>{0,0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);

        int val1 = cur->val + left[0] +right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val2, val1};
    }
public:
    int rob(TreeNode* root) {
        vector<int> result = robTree(root);
        return max(result[0],result[1]);
    }
};