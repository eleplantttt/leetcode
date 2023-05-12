//
// Created by admin on 2023/5/12.
//
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        stack<int> stk;
        stk.push(0);
        for(int i = 1;i < height.size(); i++){
            while(!stk.empty() && height[i] > height[stk.top()]){
                int mid = stk.top();
                stk.pop();
                if(!stk.empty()){
                    int w = i - stk.top() - 1;
                    int h = min(height[stk.top()], height[i]) - height[mid];
                    res += w * h;
                }
            }
            stk.push(i);
        }
        return res;
    }
};