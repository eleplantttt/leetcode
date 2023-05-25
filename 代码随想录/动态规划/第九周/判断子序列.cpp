//
// Created by admin on 2023/5/25.
//
//判断s是不是t的子序列，则只能删除t的字符也就是j，
//初始化也要size（）+1
//时间复杂度：O(n × m)
//空间复杂度：O(n × m)
bool isSubsequence(string s, string t) {
    vector<vector<int>> dp(s.size() + 1,vector<int>(t.size() + 1,0));
    for(int i = 1 ; i <= s.size() ; i++){
        for(int j = 1 ; j <= t.size() ; j++){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    if (dp[s.size()][t.size()] == s.size()) return true;
    return false;
}