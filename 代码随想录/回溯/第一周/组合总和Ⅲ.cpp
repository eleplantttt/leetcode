//
// Created by admin on 2023/6/7.
//
//- 递归函数参数返回值：sum（int）为已经收集的元素的总和，也就是path里元素的总和。startIndex（int）为下一层for循环搜索的起始位置。
//- 递归终止条件：所以如果path.size() 和 k相等了，就终止。如果此时path里收集到的元素和（sum） 和targetSum（就是题目描述的n）相同了，就用result收集当前的结果。
//- 单层递归逻辑：集合固定的就是9个数[1,...,9]，所以for循环固定i<=9
//剪枝优化：i <= 9 - (k - path.size()) + 1  记得把回溯做了and sum大于n
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int k , int n, int sum, int startIndex) {
        if (path.size() == k) {
            if(n == sum) {
                res.push_back(path);
            }
            return;
        }

        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){
            path.push_back(i);
            sum += i;
            if(sum > n) {
                sum -= i;
                path.pop_back();
                return;
            }
            dfs(k, n, sum, i + 1);
            sum -= i ;
            path.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 0, 1);
        return res;
    }
};
//- 时间复杂度: O(n * 2^n)
//- 空间复杂度: O(n)