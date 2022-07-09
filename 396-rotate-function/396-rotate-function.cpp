class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int max_ans=0;
        int ans=0,sum=0;
        for(int i=0;i<n;i++){
            ans+=(i*nums[i]);
            sum+=nums[i];
        }
        max_ans=ans;
        for(int i=n-1;i>=0;i--){
            ans=ans+sum-n*(nums[i]);
            max_ans=max(max_ans, ans);
        }
        return max_ans;
    }
};