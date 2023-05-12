//
// Created by admin on 2023/5/12.
//
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