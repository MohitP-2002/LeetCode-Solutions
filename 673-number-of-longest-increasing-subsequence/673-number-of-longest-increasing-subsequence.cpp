class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n =nums.size();
        int max=0,ans=0;
        vector<pair<int,int>> dp(n,{1,1});
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] > nums[j]){
                    if(dp[i].first == dp[j].first + 1)dp[i].second += dp[j].second;
                    if(dp[i].first < dp[j].first + 1)dp[i] = {dp[j].first + 1, dp[j].second};
                }
            }
            if(max==dp[i].first) ans+=dp[i].second;
            if(max<dp[i].first){
                ans=dp[i].second;
                max=dp[i].first;
            }
        }
        return ans;
    }
};