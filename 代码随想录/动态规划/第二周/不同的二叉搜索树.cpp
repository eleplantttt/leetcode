//
// Created by admin on 2023/5/16.
//  dp初始化为全0，0个节点也算一棵二叉搜索树，单独初始化dp[0] = 1
//  dp[i] ： 1到i为节点组成的二叉搜索树的个数为dp[i]
//  dp[i] += dp[j - 1] * dp[i - j]; ，j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量
//搜索树 中间j，左边有j-1个节点， 右边有i-j个节点  节点数是一样的，
int numTrees(int n) {
    vector<int> dp(n+1);
    dp[0] = 1;
    for(int i = 1;i <= n; i++ ){
        for(int j = 1;j <=i; j++){
            dp[i] +=dp[j-1]*dp[i-j];
        }
    }
    return dp[n];
}