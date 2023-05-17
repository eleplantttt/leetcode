//
// Created by admin on 2023/5/17.
//和上一题一样，不同在于结果的判断条件sum-dp[target]  为大石头  dp[target]为小石头相减即为答案

int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for(int i = 0; i < stones.size(); ++i){
        sum += stones[i];
    }
    int target = sum/2;
    vector<int> dp(target+1, 0);
    for(int i = 0; i < stones.size(); ++i){
        for(int j = target; j >= stones[i]; --j){
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return (sum - dp[target])- dp[target];
}