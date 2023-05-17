//
// Created by admin on 2023/5/17.
//问题转化：加法总和x 减法总和sum-x 要得到x - (sum - x) = target  ；x = (target + sum) / 2
//此时问题就转化为，装满容量为x的背包，有几种方法。
//dp[0] = 1
//nums放在外循环，target在内循环，且内循环倒序
//递推：组合类问题的公式
int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for(int i = 0;i < nums.size(); ++i){
        sum += nums[i];
    }
    if((sum + target) % 2 == 1) return 0;
    if(abs(target) > sum) return 0;

    int bagsize = (sum + target) / 2;
    vector<int> dp(bagsize + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < nums.size(); i++){
        for (int j = bagsize; j >=nums[i]; --j){
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[bagsize];
}
