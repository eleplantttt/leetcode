//
// Created by admin on 2023/6/8.
//
//1. 本题candidates 中的每个数字在每个组合中只能使用一次。
//2. 本题数组candidates的元素是有重复的，而39.组合总和 (opens new window)是无重复元素的数组candidates
//        先排序然后使用startIndex来去重，判断是否相等然后树层去重
//if(i > startIndex && candidates[i] == candidates[i-1]) {
//continue;
//}
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<int> &candidates,int target, int sum, int startIndex) {
        if (sum == target) {
            res.push_back(path);
            return;
        }

        for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            if(i > startIndex && candidates[i] == candidates[i-1]) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            dfs(candidates, target, sum, i+1);
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, 0, 0);
        return res;
    }
};
//- 时间复杂度: O(n * 2^n)
//- 空间复杂度: O(n)