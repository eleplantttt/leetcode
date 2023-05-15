//
// Created by admin on 2023/5/12.
//还是按照单调栈套路，主要是对nums2进行单调栈，并将nums1值和索引放入哈希表中，最后按照哈希表来找到nums1中的值在nums2中对应值的右边最大值，索引仍按照nums1。
//Tips：
//  - 在循环里，需要判断nums1的值是不是在nums2中存在，存在的话就可以存结果
//  - 需要先将nums1的值和索引放入哈希表，值为key；
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