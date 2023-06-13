//
// Created by admin on 2023/6/13.
//
//- 递归函数参数
//        首先排列是有序的，也就是说 [1,2] 和 [2,1] 是两个集合，这和之前分析的子集以及组合所不同的地方。
//- 递归终止条件、
//大小为原数组size
//- 单层搜索逻辑
//        这里和77.组合问题 (opens new window)、131.切割问题 (opens new window)和78.子集问题 (opens new window)最大的不同就是for循环里不用startIndex了。
//因为排列问题，每次都要从头开始搜索，例如元素1在[1,2]中已经使用过了，但是在[2,1]中还要再使用一次1。
//而used数组，其实就是记录此时path里都有哪些元素使用了，一个排列里一个元素只能使用一次。
class Solution {
private:
    vector<int> path;
    vector<vector<int>> res;

    void dfs(vector<int>& nums, vector<bool>& used){
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if (used[i] == 1) continue;
            used[i] = true;
            path.push_back(nums[i]);
            dfs(nums, used);
            path.pop_back();
            used[i] = false;
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};
//- 时间复杂度: O(n!)
//- 空间复杂度: O(n)