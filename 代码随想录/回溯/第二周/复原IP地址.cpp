//
// Created by admin on 2023/6/9.
//
//- 递归函数参数返回值：
//startIndex一定是需要的，因为不能重复分割，记录下一层递归分割的起始位置。
//本题我们还需要一个变量pointNum，记录添加逗点的数量。
//- 递归终止条件：
//pointNum表示逗点数量，pointNum为3说明字符串分成了4段了。然后验证一下第四段是否合法，如果合法就加入到结果集里
//- 单层递归逻辑
//先判断在for (int i = startIndex; i < s.size(); i++)循环中 [startIndex, i] 这个区间就是截取的子串，需要判断这个子串是否合法。
//递归调用时，下一层递归的startIndex要从i+2开始（因为需要在字符串中加入了分隔符.），同时记录分割符的数量pointNum 要 +1。
//回溯的时候，就将刚刚加入的分隔符. 删掉就可以了，pointNum也要-1。
//
//判断字串是否合法：
//- 段位以0为开头的数字不合法
//- 段位里有非正整数字符不合法
//- 段位如果大于255了不合法
class Solution {

private:
    vector<string> result;
    void dfs(string &s, int startIndex , int pointNum){
        if(pointNum ==3){
            if(isValid(s, startIndex,s.size() - 1)){
                result.push_back(s);
            }
            return;
        }
        for(int i = startIndex;i < s.size(); i++){
            if (isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                dfs(s, i + 2,pointNum);
                pointNum--;
                s.erase(s.begin() + i + 1);
            }else break;
        }
    }

    bool isValid(const string & s,int start, int end){
        if (start > end){
            return false;
        }
        if (s[start] == '0' && start != end){
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if (num > 255){
                return false;
            }
        }
        return true;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12) return result;
        dfs(s,0,0);
        return result;
    }
};
//- 时间复杂度: O(3^4)，IP地址最多包含4个数字，每个数字最多有3种可能的分割方式，则搜索树的最大深度为4，每个节点最多有3个子节点。
//- 空间复杂度: O(n)