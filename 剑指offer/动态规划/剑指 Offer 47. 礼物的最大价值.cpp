//
// Created by admin on 2023/5/22.
//
//- 时间复杂度：O(mn)
//- 空间复杂度：O(mn)
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        dp = grid;
        for(int i = 1; i < m; i++){
            dp[i][0] += dp[i-1][0];
        }
        for(int j = 1; j < n; j++){
            dp[0][j] += dp[0][j-1];
        }
        for(int i = 1;i < m; i++){
            for(int j = 1; j < n;j++){
                dp[i][j] = max(dp[i-1][j]+grid[i][j],dp[i][j-1] + grid[i][j]);
            }
        }
        return dp[m-1][n-1];
    }
};
//- 时间复杂度：O(mn)
//- 空间复杂度：O(n)
int maxValue(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<int>dp(n,0);
    for(int i = 0;i < m; i++){
        dp[0] += grid[i][0];
        for(int j = 1; j < n;j++){
            dp[j] = max(dp[j-1],dp[j]) + grid[i][j];
        }
    }
    return dp[n-1];
}
//- 时间复杂度：O(mn)
//- 空间复杂度：O(1)
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        // 动态规划方式实现
        // 在上次提交的基础上进行优化，将空间复杂度优化到O(1)

        if (grid.empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();

        //初始化第一行；第一行只能从左边进入
        for(int j=1; j<n; j++) {
            grid[0][j] += grid[0][j-1];
        }

        //初始化第一列；第一列只能从上边进入
        for(int i=1; i<m; i++) {
            grid[i][0] += grid[i-1][0];
        }

        //动态规划计算
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
            }
        }

        return grid[m-1][n-1];
    }
};