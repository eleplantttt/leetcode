//
// Created by admin on 2023/5/20.
//比Ⅱ对一个手续费，即在每次卖出的时候减去手续费
int maxProfit(vector<int>& prices, int fee) {
    int len = prices.size();
    vector<vector<int>> dp(2, vector<int>(2)); // 注意这里只开辟了一个2 * 2大小的二维数组
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; i++) {
        dp[i % 2][0] = max(dp[(i-1) % 2][0], dp[(i-1) % 2][1] - prices[i]);
        dp[i % 2][1] = max(dp[(i-1) % 2][1], dp[(i-1) % 2][0] + prices[i] - fee);
    }
    return dp[(len - 1) % 2][1];
}