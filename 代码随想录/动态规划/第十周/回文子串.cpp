//
// Created by admin on 2023/5/26.
//
//动态规划
//- 情况一：下标i 与 j相同，同一个字符例如a，当然是回文子串
//- 情况二：下标i 与 j相差为1，例如aa，也是回文子串
//- 情况三：下标：i 与 j相差大于1的时候，例如cabac，此时s[i]与s[j]已经相同了，我们看i到j区间是不是回文子串就看aba是不是回文就可以了，那么aba的区间就是 i+1 与 j-1区间，这个区间是不是回文就看dp[i + 1][j - 1]是否为true。
int countSubstrings(string s) {
    vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
    int result = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        for (int j = i; j < s.size(); j++) {
            if (s[i] == s[j] && (j - i <= 1 || dp[i + 1][j - 1])) {
                result++;
                dp[i][j] = true;
            }
        }
    }
    return result；
}
};
//- 时间复杂度：O(n^2)
//- 空间复杂度：O(n^2)



//双指针
//        在遍历中心点的时候，要注意中心点有两种情况。
//一个元素可以作为中心点，两个元素也可以作为中心点。
int countSubstrings(string s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        result += extend(s, i, i, s.size()); // 以i为中心
        result += extend(s, i, i + 1, s.size()); // 以i和i+1为中心
    }
    return result;
}
int extend(const string& s, int i, int j, int n) {
    int res = 0;
    while (i >= 0 && j < n && s[i] == s[j]) {
        i--;
        j++;
        res++;
    }
    return res;
}
//- 时间复杂度：O(n^2)
//- 空间复杂度：O(1)