class Solution {
public:
    int helper(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        dp[0]=0;
        dp[1]=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            dp[i+1]=max(nums[i]+dp[i-1],dp[i]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);
        
        return max(helper(numsA), helper(numsB));
    }
};