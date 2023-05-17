//
// Created by admin on 2023/5/17.
//01背包问题，求出总和sum，等和情况则target == sum / 2,
//则背包容量为target，则问题为装满target的背包问题，每一个书只能取一次
//初始化记得dp（target+1,0)      target+1   背包不能为0的
//  内存循环需要递减，防止重复取值，因为每个数只能取一次。
//  dp[j]表示 背包总容量（所能装的总重量）是j，放进物品后，背的最大重量为dp[j]
//最后判断条件：
//  dp[target] == target   左边dp[target]装满了 右边sum的一半，说明能分割成功。

bool canPartition(vector<int>& nums) {
    int sum = 0;

    for(int i = 0; i < nums.size(); i++){
        sum += nums[i];
    }
    if(sum % 2 ==1) return false;

    int target = sum / 2;
    vector<int> dp(target + 1, 0);
    for(int i = 0; i < nums.size(); i++ ){                  //物品
        for(int j = target; j >= nums[i]; j--){             //背包
            dp[j] = max(dp[j], dp[j-nums[i]] + nums[i]);
        }
    }

    if(dp[target] == target) {
        return true;
    }
    return false;
}