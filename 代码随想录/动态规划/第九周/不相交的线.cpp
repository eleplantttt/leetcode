//
// Created by admin on 2023/5/25.
//
//求绘制的最大连线数，其实就是求两个字符串的最长公共子序列的长度！
//与上一题最长公共子序列长度
//- 时间复杂度: O(n * m)
//- 空间复杂度: O(n * m)


int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1, 0));
    for(int i = 1; i <= nums1.size(); i++){
        for(int j = 1;j <= nums2.size();j++){
            if(nums1[i-1] == nums2[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[nums1.size()][nums2.size()];
}