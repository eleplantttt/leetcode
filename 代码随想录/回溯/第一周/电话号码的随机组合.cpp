//
// Created by admin on 2023/6/7.
//
//- 递归函数参数返回值：这个index是记录遍历第几个数字了，就是用来遍历digits的（题目中给出数字字符串），同时index也表示树的深度。
//- 递归终止条件：index 等于 输入的数字个数（digits.size）了（本来index就是用来遍历digits的）0进一次1进一次，index为2 等于digits.size则收集结果返回
//- 单层递归逻辑：首先要取index指向的数字，并找到对应的字符集（手机键盘的字符集）。然后for循环来处理这个字符集
class Solution {
private:
    const string letterMap[10] = {
            "", // 0
            "", // 1
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz",
    };
    vector<string> ans;
    string path;

    void dfs(const string& digits, int index) {
        if(index == digits.size()) {
            ans.push_back(path);
            return;
        }

        int digit = digits[index] - '0';
        string letters = letterMap[digit];
        for(int i = 0; i < letters.size(); i++) {
            path.push_back(letters[i]);
            dfs(digits, index + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        dfs(digits, 0);
        return ans;
    }
};
//- 时间复杂度: O(3^m * 4^n)，其中 m 是对应四个字母的数字个数，n 是对应三个字母的数字个数
//- 空间复杂度: O(3^m * 4^n)