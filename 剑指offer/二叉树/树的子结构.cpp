//
// Created by admin on 2023/6/14.
//
/**
 * 判断B是不是A的子结构：首先特判，两个树任何一个为空则返回false，接着分三种情况
- 以当前根节点也就是A为根节点的树包含B
- 当B节点为空：B已匹配完成，（越过叶子节点），因此返回true （终止条件）；
- 当A节点为空：A越过叶子节点），因此返回false （终止条件）；
- A和B节点值不同：匹配失败，返回false；
- 接下来就是相同的情况，根节点相同了，左子树和右子树都要相同才能判断相同。
- A的左子树里面藏着B结构（不一定是A的左子树节点为头的）
- B的右子树里面藏着B结构（不一定是A的右子树节点为头的）
 */

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    bool recur (TreeNode* A, TreeNode* B) {
        if (!B) return true;
        if (!A || A->val != B->val) return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (!A || !B) {
            return false;
        }
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
};

/*
- 时间复杂度：O(MN)
- 空间复杂度：O(M)
 */
