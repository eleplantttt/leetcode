//
// Created by admin on 2023/5/12.
//单调栈规则相同，主要是计算结果的步骤需要考虑，当遍历到当前元素比栈顶元素大时，记下栈顶元素，然后将其弹出，
// 然后判断栈是否为空，不为空则看栈顶与前一个栈顶与当前元素的面积，取栈顶和当前的最小，并减去刚刚弹出的栈顶就是高度。循环计算，此时的计算规则的按照横向计算。
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