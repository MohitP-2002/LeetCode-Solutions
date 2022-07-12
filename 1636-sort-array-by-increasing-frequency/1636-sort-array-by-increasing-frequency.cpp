class Solution {
public:
    static bool comp(pair<int,int> a, pair<int,int> b){
        return (a.first==b.first)?a.second>b.second:a.first<b.first;
    }
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        vector<pair<int,int>> v;
        for(auto i:m){
            v.push_back({i.second,i.first});
        }
        sort(v.begin(), v.end(), comp);
        nums.clear();
        for(auto i:v){
            for(int j=0;j<i.first;j++){
                nums.push_back(i.second);
            }
        }
        return nums;
    }
};