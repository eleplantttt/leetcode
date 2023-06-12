//
// Created by admin on 2023/6/12.
//
//这道题目和78.子集 (opens new window)区别就是集合里有重复元素了，而且求取的子集要去重。
//增加了了去重即
//if(i > startIndex && nums[i] == nums[i-1]){
//continue;
}
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int>& nums, int startIndex) {
        res.push_back(path);
        for (int i = startIndex; i < nums.size(); i++) {
            if(i > startIndex && nums[i] == nums[i-1]){
                continue;
            }
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }
};
//- 时间复杂度: O(n * 2^n)
//- 空间复杂度: O(n)
