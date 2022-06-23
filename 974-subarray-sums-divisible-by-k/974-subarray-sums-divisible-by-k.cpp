class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int prefix=0, count=0;
        for(int i=0;i<nums.size();i++){
            prefix=(prefix + nums[i]%k +k)%k;
            count+=m[prefix];
            m[prefix]++;
        }
        return count;
    }
};