//
// Created by admin on 2023/5/21.
//本题含有一天的冷冻期，则有四个状态，状态一：今天持有，今天不持有分为两种状态，分别是状态二：前几天就卖出了一直没操作今天可以买入的状态，和状态三：今天卖出的状态，状态四：今天冷冻期
//- 状态一可以由昨天就持有的状态一dp[i-1][0]和状态二中今天买入的状态二dp[i - 1][1] - prices[i]推出和昨天是冷冻期今天买入的状态四dp[i-1][3] - prices[i]；
//- 状态二可以由前几天就卖出的状态二和昨天是冷冻期的状态四推导；
//- 状态三只能由今天卖出的状态可以由昨天持有-今日价格推出。
//- 状态四只能由昨天卖出的状态推导。
//最后返回状态二三四的最大值，全都是不持有股票的状态。
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n ==0 ) return 0;
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = -prices[0];
    for(int i = 1; i < n; ++i){
        dp[i][0] = max(dp[i-1][0],max(dp[i-1][3] - prices[i], dp[i - 1][1] - prices[i]));
        dp[i][1] = max(dp[i-1][1],dp[i-1][3]);
        dp[i][2] = dp[i-1][0] + prices[i];
        dp[i][3] = dp[i-1][2];
    }
    return max(dp[n-1][3],max(dp[n-1][1],dp[n-1][2]));
}