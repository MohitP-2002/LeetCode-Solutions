class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
         int aSum=0;
        for(int i=0;i<=n;i++){
            aSum+=i;
        }
        int sum=0;
        for(auto i:nums){
            sum+=i;
        }
        return aSum-sum;
    }
};