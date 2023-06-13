//
// Created by admin on 2023/6/13.
//
//这道题目和46.全排列 (opens new window)的区别在与给定一个可包含重复数字的序列，要返回所有不重复的全排列。在40.组合总和II (opens new window)、90.子集II (opens new window)我们分别详细讲解了组合问题和子集问题如何去重。
//去重一定要对元素进行排序，这样我们才方便通过相邻的节点来判断是否重复使用了。对于排列问题，树层上去重和树枝上去重，都是可以的，但是树层上去重效率更高！
//一般来说：组合问题和排列问题是在树形结构的叶子节点上收集结果，而子集问题就是取树上所有节点的结果。
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
            if(i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;
            if (used[i] == false) {
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, used);
                path.pop_back();
                used[i] = false;
            }

        }

    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        dfs(nums, used);
        return res;
    }
};
//- 时间复杂度: O(n*n!)
//- 空间复杂度: O(n)