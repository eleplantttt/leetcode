//
// Created by admin on 2023/6/8.
//
//一个集合来求组合的话，就需要startIndex，例如：77.组合 (opens new window)，216.组合总和III
//多个集合取组合，各个集合之间相互不影响，那么就不用startIndex例如：17.电话号码的字母组合
//无重复元素，但是可以重复选取，则可以先排序，按照从小到大取，单层搜索策略里面下一层不用再 i+1
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &candidates, int target, int sum, int startIndex) {
        if(sum == target) {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // 需要排序
        dfs(candidates, target, 0, 0);
        return res;
    }
};
//- 时间复杂度: O(n * 2^n)，注意这只是复杂度的上界，因为剪枝的存在，真实的时间复杂度远小于此
//- 空间复杂度: O(target)