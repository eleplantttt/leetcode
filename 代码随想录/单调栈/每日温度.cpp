//
// Created by admin on 2023/5/12.
//新建一个单调栈和结果数组，单调栈入栈规则是如果比栈顶小（等于）则直接入栈，大于栈顶则找到比其大的值，则弹出栈顶，循环弹出到栈顶比他大，则单调栈是从栈底到栈顶永远是是递减的，找右边比此时大的值。
//Tips:
//  - 初始化结果数组的值根据题目判断一般为0，也有可能为-1；
//  - 注意循环里面判断条件  栈不能为空
//  - 不用先将0索引push进栈里
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stk;
        vector<int> res(temperatures.size(), 0);
        stk.push(0);
        for(int i = 1; i < temperatures.size(); i++){
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]){
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
