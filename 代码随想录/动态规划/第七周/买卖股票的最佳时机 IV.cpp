//
// Created by admin on 2023/5/21.
//相比上一题，完成k次交易，则有k次买入卖出，可以放入一个循环。
//dp[i][j] 中i为第i天的状态为j，j的意思是第几次持有或卖出。
//基数为持有，偶数为卖出，则初始化到2k-1
//遍历时i从第一天开始遍历，遍历到最后一天，j一次遍历分奇偶，也就是先算持有再算卖出。
//更新持有状态为前一次持有，和当天买入也就是上一天卖出状态减今日股票价格

int maxProfit(int k, vector<int>& prices) {
    if(prices.size() == 0) return 0;
    vector<vector<int>> dp(prices.size(),vector<int>(2 * k + 1,0));
    for(int j = 1;j < 2 * k;j += 2){
        dp[0][j] = -prices[0];
    }
    for(int i = 1;i < prices.size(); ++i){
        for(int j = 0; j < 2 * k -1;j += 2){
            dp[i][j+1] = max(dp[i-1][j+1], dp[i-1][j] - prices[i]);
            dp[i][j+2] = max(dp[i-1][j+2], dp[i-1][j+1] + prices[i]);
        }
    }
    return dp[prices.size() - 1][2 * k];
}

