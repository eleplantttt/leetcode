//
// Created by admin on 2023/5/15.
//滚动数组 i从2开始
int minCostClimbingStairs(vector<int>& cost) {
    int dp0 = 0;
    int dp1 = 0;
    for(int i = 2; i<=cost.size(); i++){
        int dpi = min(dp1 + cost[i - 1], dp0 + cost[i - 2]);
        dp0 = dp1;
        dp1 = dpi;
    }
    return dp1;
}