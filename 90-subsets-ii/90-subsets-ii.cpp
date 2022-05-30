class Solution {
public:
    vector<vector<int>> ans;
    void generate(vector<int>& nums, int i, vector<int>& subset){
        ans.push_back(subset);
        for(int k=i;k<nums.size();k++){
            //for removing duplicate subsets
            if(k==i || nums[k]!=nums[k-1]){
                subset.push_back(nums[k]);
                generate(nums,k+1,subset);
                subset.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        generate(nums,0,subset);
        return ans;
    }
};