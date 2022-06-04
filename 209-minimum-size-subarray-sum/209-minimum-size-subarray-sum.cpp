class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int len=INT_MAX;
        int i=0,j=0,n=nums.size();
        while(j<n){
            sum+=nums[j++];
            while(sum>=target){
                len=min(len,j-i);
                sum-=nums[i++];
            }
        }
        return len==INT_MAX?0:len;
    }
};