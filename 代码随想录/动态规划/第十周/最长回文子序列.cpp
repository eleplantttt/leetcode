//
// Created by admin on 2023/5/26.
//
//- 如果s[i]与s[j]相同，那么dp[i][j] = dp[i + 1][j - 1] + 2;
//- 如果s[i]与s[j]不相同，说明s[i]和s[j]的同时加入 并不能增加[i,j]区间回文子序列的长度，那么分别加入s[i]、s[j]看看哪一个可以组成最长的回文子序列。
//加入s[j]的回文子序列长度为dp[i + 1][j]。加入s[i]的回文子序列长度为dp[i][j - 1]。
int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
    for (int i = s.size() - 2; i >= 0; i--) {
        for (int j = i + 1; j < s.size() ; ++j) {
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            } else{
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }
    return dp[0][s.size()-1];
}
//- 时间复杂度: O(n^2)
//- 空间复杂度: O(n^2)