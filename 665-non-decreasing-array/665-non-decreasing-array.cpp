class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool flag = false;
        for(int i=0;i<nums.size()-1;i++){
            if(i!=0 && nums[i]>=nums[i-1] && nums[i]>nums[i+1] && nums[i+1]<nums[i-1] && !flag){
                nums[i+1]=nums[i];
                flag = true;
                continue;
            }
            if(nums[i] > nums[i+1]){
                if(flag){
                    return false;
                }
                nums[i]=nums[i+1];
                flag = true;
                if(i!=0 && nums[i] < nums[i-1]  && flag) return false;
            }
        }
        return true;
    }
};