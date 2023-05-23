//
// Created by admin on 2023/5/23.
//  - 需要特判
//  - 初始化为1，dp[i]表示i之前包括i的以nums[i]结尾的最长递增子序列的长度
//  - i在外层从1开始，j在内层j<i,两个递增子序列最后一位数的比较。
//  - 最后需要将dp[i]存入res
int lengthOfLIS(vector<int>& nums) {
    if(nums.size() <= 1) return nums.size();
    vector<int> dp(nums.size(), 1);
    int res = 0;
    for(int i = 1; i< nums.size(); i++){
        for(int j = 0; j < i; j++){
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if(dp[i] > res) res = dp[i];
    }
    return res;
}