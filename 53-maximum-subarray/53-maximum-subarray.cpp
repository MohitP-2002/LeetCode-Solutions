class Solution {
public:
    //maximum subarray using kadane's algorithm
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int sum=INT_MIN, cur_sum=0;
        for(int i=0;i<n;i++){
            cur_sum+=nums[i];
            sum=max(sum,cur_sum);
            if(cur_sum<0) cur_sum=0;
        }
        return sum;
    }
};