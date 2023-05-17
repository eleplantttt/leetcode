//
// Created by admin on 2023/5/17.
//完全背包，物品随便取，可以重复。
//本题为组合个数
//如果求组合数就是外层for循环遍历物品，内层for遍历背包。
//如果求排列数就是外层for遍历背包，内层for循环遍历物品。
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount+1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); ++i){
        for (int j = coins[i]; j <= amount; ++j){
            dp[j] += dp[j - coins[i]];
        }
    }
    return dp[amount];
}