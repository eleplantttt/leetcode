//
// Created by admin on 2023/5/16.
//从n = 3开始拆分，dp[0] = 0,dp[1] = 0,dp[2] = 1;
//i从3开始遍历，因为正整数就从1开始遍历
int integerBreak(int n) {
    vector<int> dp(n+1);
    dp[2] = 1;
    for(int i = 3; i < n; i++){
        for(int j = 1;j <= i/2; j++ ){
            dp[i] = max(dp[i], max(dp[i-j] * j,(i-j)*j);
        }
    }
    return dp[n];
}