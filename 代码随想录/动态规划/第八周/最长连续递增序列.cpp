//
// Created by admin on 2023/5/23.
//  - 特判
//  - 用一个count来重置不连续的序列，将最大的count存入res。
int findLengthOfLCIS(vector<int>& nums) {
    if(nums.size() == 0) return 0;
    int res = 1;
    int count = 1;
    for(int i = 1;i < nums.size();i++){
        if(nums[i] > nums[i-1]){
            count++;
        }else{
            count = 1;
        }
        if(count > res) res = count;
    }
    return res;
}