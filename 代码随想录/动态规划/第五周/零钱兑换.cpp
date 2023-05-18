//
// Created by admin on 2023/5/18.
//算的是最小个数
//初始化应该初始最大值
//背包和物品的遍历顺序没有关系
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for(int i = 0; i < coins.size();i++){
        for(int j = coins[i]; j <= amount; j++){
            if(dp[j - coins[i]] != INT_MAX){
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }
    }
    if(dp[amount] == INT_MAX) return -1;
    return dp[amount];
}