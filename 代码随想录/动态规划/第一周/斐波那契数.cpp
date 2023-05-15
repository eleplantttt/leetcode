//
// Created by admin on 2023/5/15.
//首先①判断边界，②定义dp[2],③初始化，④遍历递推关系，滚动数组。
int fib(int n) {
    if(n < 2) return n;
    int dp[2];
    dp[0] = 0;
    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        int sum = dp[0] + dp[1];
        dp[0] = dp[1];
        dp[1] = sum;
    }
    return dp[1];
}