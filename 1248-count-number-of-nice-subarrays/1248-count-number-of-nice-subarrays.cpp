class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>v(n+1,0);
        int odd=0,ans=0;
        for(int i=0;i<n;i++){
            v[odd]++;
            if(nums[i]&1) odd++;
            if(odd>=k){
                ans+=v[odd-k];
            }
        }
        return ans;
    }
};