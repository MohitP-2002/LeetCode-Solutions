class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int count=0;
        int left=0,pdt=1;
        for(int i=0;i<nums.size();i++){
            pdt*=nums[i];
            while(pdt>=k){
                pdt/=nums[left];
                left++;
            }
            count+=i-left+1;
        }
        return count;
    }
};