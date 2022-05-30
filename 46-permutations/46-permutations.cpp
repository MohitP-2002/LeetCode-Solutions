class Solution {
public:
    vector<vector<int>> ans;
    void permute(vector<int> & nums, int begin,int end){
        if(begin==end){
            ans.push_back(nums);
        }
        for(int i=begin;i<=end;i++){
            swap(nums[i],nums[begin]);
            permute(nums,begin+1,end);
            swap(nums[i],nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        permute(nums,0,nums.size()-1);
        return ans;
    }
};