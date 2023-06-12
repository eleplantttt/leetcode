//
// Created by admin on 2023/6/12.
//
//与子集Ⅱ不同，这里没有使用哈希表去重，因为本题的数值固定，可以用数组值来做哈希，再每层里面判断不是递增的或者已经用过
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& nums, int startIndex) {
        if (path.size() > 1) {
            res.push_back(path);
        }
        int used[201] = {0};
        for (int i = startIndex; i < nums.size(); i++) {
            if ((!path.empty() && nums[i] < path.back()) || used[nums[i] + 100] == 1) {
                continue;
            }
            used[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            dfs(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(nums, 0);
        return res;
    }
};
//时间复杂度: O(n * 2^n)
//空间复杂度: O(n)