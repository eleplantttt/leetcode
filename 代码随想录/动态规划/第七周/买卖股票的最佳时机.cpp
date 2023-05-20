//
// Created by admin on 2023/5/20.
//动态规划
//- dp[i][0] 表示第i天持有股票所得现金。
//- dp[i][1] 表示第i天不持有股票所得最多现金

//- dp[i][0] 表示第i天持有股票所得现金。
//- dp[i][1] 表示第i天不持有股票所得最多现金
//        第i天持有股票即dp[i][1]
//- 不同点在于可以多次买卖，则持有股票的状态可以由昨天不持有而今天买入dp[i - 1][1] - prices[i]和昨天就持有推导dp[i - 1][0]
//再来看看如果第i天不持有股票即dp[i][1]的情况， 依然可以由两个状态推出来
//- 第i-1天就不持有股票，那么就保持现状，所得现金就是昨天不持有股票的所得现金 即：dp[i - 1][1]
//- 第i天卖出股票，所得现金就是按照今天股票价格卖出后所得现金即：prices[i] + dp[i - 1][0]
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(2, vector<int>(2));
    dp[0][0] = -prices[0];
    dp[0][1] = 0;
    for(int i = 1; i < prices.size(); ++i){
        dp[i % 2][0] = max(dp[(i-1) % 2][0], -prices[i]);
        dp[i % 2][1] = max(dp[(i-1) % 2][1],dp[(i-1) % 2][0] + prices[i]);
    }
    return dp[(prices.size()-1) % 2][1];
}

//贪心
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int res = 0;
        for(int i = 0; i < prices.size(); ++i){
            low = min(low, prices[i]);
            res = max(res, prices[i] - low);
        }
        return res;
    }
};
