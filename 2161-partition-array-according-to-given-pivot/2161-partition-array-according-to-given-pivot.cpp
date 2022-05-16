class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> v1,v2,v3;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot) v1.push_back(nums[i]);
            else if(nums[i]==pivot) v2.push_back(nums[i]);
            else v3.push_back(nums[i]);
        }
        nums.clear();
        for(auto i:v1) nums.push_back(i);
        for(auto i:v2) nums.push_back(i);
        for(auto i:v3) nums.push_back(i);
        return nums;
    }
};