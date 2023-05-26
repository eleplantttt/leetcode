//
// Created by admin on 2023/5/26.
//
//递推
//- 操作一：word1删除一个元素，那么就是以下标i - 2为结尾的word1 与 j-1为结尾的word2的最近编辑距离 再加上一个操作。
//即 dp[i][j] = dp[i - 1][j] + 1;
//- 操作二：word2删除一个元素，那么就是以下标i - 1为结尾的word1 与 j-2为结尾的word2的最近编辑距离 再加上一个操作。
//即 dp[i][j] = dp[i][j - 1] + 1;
//- 操作三：替换元素，word1替换word1[i - 1]，使其与word2[j - 1]相同，此时不用增删加元素。
//可以回顾一下，if (word1[i - 1] == word2[j - 1])的时候我们的操作 是 dp[i][j] = dp[i - 1][j - 1] 对吧。
//那么只需要一次替换的操作，就可以让 word1[i - 1] 和 word2[j - 1] 相同。
//所以 dp[i][j] = dp[i - 1][j - 1] + 1;
//- 时间复杂度: O(n * m)
//- 空间复杂度: O(n * m)
int minDistance(string word1, string word2) {
    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
    for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
    for (int i = 1; i <= word1.size(); i++) {
        for (int j = 1; j <= word2.size(); j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }
    return dp[word1.size()][word2.size()];
}