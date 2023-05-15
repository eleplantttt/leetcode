//
// Created by admin on 2023/5/12.
//相当于一个循环数组的问题，选择将两个nums拼接，索引按照对原数组长度取余计算。
//其他的与每日温度一样。
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        if(nums.size() == 0) return res;
        stack<int> st;
        for(int i = 0; i < nums.size()*2; i++){
            while(!st.empty() && nums[i % nums.size()] > nums[st.top()]){
                res[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }
        return res;
    }
};