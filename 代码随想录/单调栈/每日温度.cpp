//
// Created by admin on 2023/5/12.
//
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
