//
// Created by admin on 2023/5/17.
//两个维度的背包，需要二维数组，但是遍历顺序需要递减。
//dp[i][j] = max(dp[i][j], dp[i - zeroNums][j - oneNums] + 1)

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1,0));
    for(auto str : strs) {
        int oneNums = 0, zeroNums = 0;
        for(auto ch : str){
            if( ch == '0')  zeroNums++;
            else oneNums++;
        }
        for (int i = m; i >= zeroNums; i--){
            for (int j = n;j >= oneNums;j--){
                dp[i][j] = max(dp[i][j], dp[i - zeroNums][j - oneNums] + 1);
            }
        }
    }
    return dp[m][n];
}