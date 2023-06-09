//
// Created by admin on 2023/6/9.
//

//- 递归函数参数返回值：和组合问题一样，分割线相当于取值。
//- 递归终止条件：当如果起始位置已经大于s的大小，说明已经找到了一组分割方案了
//- 单层递归逻辑：首先判断startIndex到i是否为回文串，是的话则截取放入path，再接着画下一条分割线。
//动态规划求回文串：先计算出哪些是回文串，动态规划的算法可以跳过很多重复计算。
void computePalindrome(const string &s){
    isPalidrome.resize(s.size(), vector<bool>(s.size(), false));
    for(int i = s.size() - 1; i >= 0; i--) {
        for(int j = i; j < s.size(); j++){
            if(i == j) { isPalidrome[i][j] = true; }
            else if (j - i == 1) { isPalidrome[i][j] = (s[i]==s[j]);}
            else { isPalidrome[i][j] = (s[i] == s[j] && isPalidrome[i + 1][j - 1]); }
        }
    }
}
class Solution {
private:
    vector<string> path;
    vector<vector<string>> res;
    void dfs (const string& s, int startIndex) {
        if (startIndex >= s.size()) {
            res.push_back(path);
            return;
        }
        for(int i = startIndex; i < s.size(); i++) {
            if(isPalidrome(s, startIndex, i)) {
                string str = s.substr(startIndex, i-startIndex+1);
                path.push_back(str);
            } else {
                continue;
            }
            dfs(s, i+1);
            path.pop_back();

        }
    }

    bool isPalindrome(const string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        dfs(s,0);
        return res;
    }
};
//- 时间复杂度: O(n * 2^n)
//- 空间复杂度: O(n^2)