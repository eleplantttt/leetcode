//
// Created by admin on 2023/5/21.
//
//一共有四个状态，一个是第一次持有第一次卖出第二次持有第二次卖出分别为dp[1]/dp[2]/dp[3]dp[4]
//维护一个dp(5, 0) 的vector记录每个状态。
//初始化：dp[1] = -price[0]  dp[3] = -price[0]


int maxProfit(vector<int>& prices) {
    if(prices.size() == 0) return 0;
    vector<int> dp(5, 0);
    dp[1] = -prices[0];
    dp[3] = -prices[0];
    for(int i = 1; i < prices.size(); ++i){
        dp[1] = max(dp[1], dp[0] - prices[i]);
        dp[2] = max(dp[2], dp[1] + prices[i]);
        dp[3] = max(dp[3], dp[2] - prices[i]);
        dp[4] = max(dp[4], dp[3] + prices[i]);
    }
    return dp[4];
}