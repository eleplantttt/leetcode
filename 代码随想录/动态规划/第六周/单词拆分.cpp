//
// Created by admin on 2023/5/19.
//重新开一个哈希表，保存字典内字符串
//初始化dp为 false，大小为 s.size()+1
//dp[0] = true    为了递归
//截取j到i之间的字符串去哈希表中查找有无  && dp[j]

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict) {
    unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++) {
        for(int j = 0; j < i; j++){
            string word = s.substr(j, i-j);
            if(wordSet.find(word) != wordSet.end() && dp[j]){
                dp[i] = true;
            }
        }
    }
    return dp[s.size()];
}