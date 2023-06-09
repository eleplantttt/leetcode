//
// Created by admin on 2023/6/9.
//
//如果把 子集问题、组合问题、分割问题都抽象为一棵树的话，那么组合问题和分割问题都是收集树的叶子节点，而子集问题是找树的所有节点！
//不需要终止条件。
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};
//- 时间复杂度: O(n * 2^n)
//- 空间复杂度: O(n)