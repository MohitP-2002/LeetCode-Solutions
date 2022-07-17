class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n = nums.size();
        int count=0;
        set<pair<int,int>> s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(nums[i]-nums[j]==k) s.insert({nums[i],nums[j]});
            }
        }
        return s.size();
    }
};