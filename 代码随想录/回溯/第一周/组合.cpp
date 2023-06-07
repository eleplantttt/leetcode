//
// Created by admin on 2023/6/7.
//
//- 递归函数参数及返回值：主要在如何确定回溯函数的参数，组合问题需要参数startIndex来记录下一层递归起始的位置
//- 终止条件：当收集的的个数（size）为 2 则记录并返回。
//- 单层递归逻辑：for循环横向遍历
//        剪枝优化：
//1. 已经选择的元素个数：path.size();
//2. 还需要的元素个数为: k - path.size();
//3. 在集合n中至多要从该起始位置 : n - (k - path.size()) + 1，开始遍历
class Solution {
private:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int n, int k, int startIndex) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for(int i = startIndex ; i <= n - (k - path.size()) + 1 ; i++) {
            path.push_back(i);
            dfs(n, k, i+1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1);
        return res;
    }
};