//
// Created by admin on 2023/5/25.
//
//需要特判，每次碰到子数组和为负数的时候更新，重新起一个头nums[i]。
//- 时间复杂度：O(n)
//- 空间复杂度：O(n)

int maxSubArray(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    vector<int> dp(nums.size());
    dp[0] = nums[0];
    int res = dp[0];
    for(int i = 1;i < nums.size(); i++){
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
        if(dp[i] > res) res = dp[i];
    }
    return res;
}