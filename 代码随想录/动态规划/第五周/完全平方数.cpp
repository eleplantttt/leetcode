//
// Created by admin on 2023/5/18.
//求的是最小个数
//物品为1，2，3的平方1，4，9
//背包初始值为1最小的i平方
int numSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;
    for(int i = 1; i * i <= n; i++){            //物品
        for(int j = i * i;j <= n; j++){        //背包
            dp[j] = min(dp[j - i * i] + 1, dp[j]);
        }
    }
    return dp[n];
}
