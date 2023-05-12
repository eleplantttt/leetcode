//
// Created by admin on 2023/5/12.
//
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res(nums1.size(), -1);
        stack<int> stk;
        unordered_map<int,int> mp;
        if(nums1.size() == 0) return res;
        for(int i = 0; i < nums1.size(); i++){
            mp[nums1[i]] = i;
        }

        stk.push(0);
        for(int i = 1; i < nums2.size(); i++){
            while(!stk.empty() && nums2[i] > nums2[stk.top()]){
                if(mp.count(nums2[stk.top()])){
                    int index = mp[nums2[stk.top()]];
                    res[index] = nums2[i];
                }
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
