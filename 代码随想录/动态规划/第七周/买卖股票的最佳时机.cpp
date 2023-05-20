//
// Created by admin on 2023/5/20.
//动态规划
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
