//
// Created by admin on 2023/5/15.
//主要是dp数组初始化以及大小
//遍历情况从1开始 ，（0，0）（1，0）（0，1）统一被初始化。

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m,vector<int>(n, 0));
    for(int i = 0; i < m; i++) dp[i][0] = 1;
    for(int j = 0; j < n; j++) dp[0][j] = 1;
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}