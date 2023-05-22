//
// Created by admin on 2023/5/22.
//
//- 时间复杂度：O(logn)
//- 空间复杂度：O(logn)
//空间复杂度比下面的大因为下面的滚动数组了
int translateNum(int num) {
    string src = to_string(num);
    vector<int> dp(src.size() + 1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2; i <= src.size();i++){
        dp[i] += dp[i-1];
        int temp = (src[i-2]-'0')*10 + src[i-1] - '0';
        if(src[i-2] != '0' && temp >=10 && temp <=25){
            dp[i] += dp[i-2];
        }

    }
    return dp[src.size()];
}
//- 时间复杂度：O(logn)
//- 空间复杂度：O(logn)
//虽然虽然这里用了滚动数组，动态规划部分的空间代价是 O(1) 的，但是这里用了一个临时变量把数字转化成了字符串，故渐进空间复杂度也是 O(logn)
int translateNum(int num) {
    string src = to_string(num);
    vector<int> dp(3,0);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    for(int i = 1; i <src.size();i++){
        dp[0] = dp[1];
        dp[1] = dp[2];
        dp[2] = dp[1];
        string sub = src.substr(i-1, 2);
        if(sub <= "25" && sub >= "10"){
            dp[2] += dp[0];
        }
    }
    return dp[2];
}