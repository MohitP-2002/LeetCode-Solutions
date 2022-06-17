class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> a;
        for(auto i:nums){
            a.push_back(i);
        }
        //rotate 
        for(int i=0;i<nums.size();i++){
            nums[(i+k)%(nums.size())] = a[i];
        }
    }
};