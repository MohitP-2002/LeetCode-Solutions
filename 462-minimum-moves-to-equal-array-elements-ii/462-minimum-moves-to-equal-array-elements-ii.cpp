class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long int ans=LONG_MAX;
        for(int i=0;i<nums.size();i++){
            long long int c=0;
            for(int j=0;j<nums.size();j++){
                c+=abs(nums[j]-nums[i]);
                if(c>ans) break;
            }
            ans=min(ans,c);
        }
        return ans;
    }
};