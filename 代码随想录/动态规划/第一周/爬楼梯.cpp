//
// Created by admin on 2023/5/15.
//注意初始化的条件，没有0阶的情况，直接从1和2初始化  i从3开始
int climbStairs(int n) {
    if(n < 2) return n;
    int dp[3];
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i <= n; i++){
        int sum = dp[1] + dp[2];
        dp[1] = dp[2];
        dp[2] = sum;
    }
    return dp[2];
}