//
// Created by admin on 2023/5/25.
//
//dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]
//- 一部分是用s[i - 1]来匹配，那么个数为dp[i - 1][j - 1]。即不需要考虑当前s子串和t子串的最后一位字母，所以只需要 dp[i-1][j-1]。
//- 一部分是不用s[i - 1]来匹配，个数为dp[i - 1][j]。
//初始化
//- dp[i][0] 表示：以i-1为结尾的s可以随便删除元素，出现空字符串的个数。
//那么dp[i][0]一定都是1，因为也就是把以i-1为结尾的s，删除所有元素，出现空字符串的个数就是1。
//- dp[0][j]，dp[0][j]：空字符串s可以随便删除元素，出现以j-1为结尾的字符串t的个数。
//那么dp[0][j]一定都是0，s无论如何也变成不了t。
//- dp[0][0] 应该是多少。dp[0][0]应该是1，空字符串s，可以删除0个元素，变成空字符串t。
//- 时间复杂度: O(n * m)
//- 空间复杂度: O(n * m)

int numDistinct(string s, string t) {
    vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
    for (int i = 0; i < s.size(); i++) dp[i][0] = 1;
    // for (int j = 1; j < t.size(); j++) dp[0][j] = 0;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[s.size()][t.size()];
}