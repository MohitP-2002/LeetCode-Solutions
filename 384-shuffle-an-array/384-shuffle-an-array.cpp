class Solution {
public:
    vector<int> a,res;
    Solution(vector<int>& nums) {
        a=nums;
        res=nums;
    }
    
    vector<int> reset() {
        return res;
    }
    
    vector<int> shuffle() {
        next_permutation(a.begin(), a.end());
        return a ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */