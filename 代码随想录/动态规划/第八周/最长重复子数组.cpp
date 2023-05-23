//
// Created by admin on 2023/5/23.
//
//二维dp
//        dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]
//这样设计的目的是更好初始化。
//- 若最后nums1[i - 1] == nums2[j - 1]则长度加一最后存入res
//- 时间复杂度：$$O(n × m)$$，n 为A长度，m为B长度
//- 空间复杂度：O(n × m)
int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp (nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    int result = 0;
    for (int i = 1; i <= nums1.size(); i++) {
        for (int j = 1; j <= nums2.size(); j++) {
            if (nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if (dp[i][j] > result) result = dp[i][j];
        }
    }
    return result;
}
//滚动数组
//- 时间复杂度：$$O(n × m)$$，n 为A长度，m为B长度
//- 空间复杂度：O(m)
int findLength(vector<int>& nums1, vector<int>& nums2) {
    int res = 0;
    vector<int> dp(nums2.size() + 1, 0);
    for(int i = 1;i <= nums1.size(); i++){
        for(int j = nums2.size(); j > 0; j--){
            if(nums2[j-1] == nums1[i-1]){
                dp[j] = dp[j-1] + 1;
            }else dp[j] = 0;
            res = max(dp[j], res);
        }
    }
    return res;
}