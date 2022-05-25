class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted;
        sorted=nums;
        int n = sorted.size();
        int i=0, j=n-1;
        sort(sorted.begin(),sorted.end());
        while(i<n && nums[i]==sorted[i]){
            i++;
        }
        while(j>i && nums[j]==sorted[j]) j--;
        return j-i+1;
    }
};