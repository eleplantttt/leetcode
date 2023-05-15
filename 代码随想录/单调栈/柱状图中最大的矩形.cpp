//
// Created by admin on 2023/5/12.
//最大矩形，则找此时元素左右两边比第一个他小的值，则单调栈规则与前面四题相反，但是需要注意的是头尾需要各插入元素0
//头部加0：避免了降序数组进栈，一直替换，计算结果为0，由于栈里一直只有一个元素，宽度一直为0。
//尾部加0：避免升序数组依次入栈，但是不计算结果。
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
