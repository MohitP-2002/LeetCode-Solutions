// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  static bool comp(pair<int,int> a, pair<int,int> b){
      return (a.first==b.first)?a.second>b.second:a.first>b.first;
  }
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        sort(nums.begin(),nums.end());
        vector<int> v;
        unordered_map<int,int> m;
        for(auto  i: nums) {
            m[i]++;
        }
        vector<pair<int,int>> p;
        for(auto i:m){
            p.push_back({i.second,i.first});
        }
        sort(p.begin(),p.end(),comp);
        int c=0;
        while(c!=k){
            v.push_back(p[c++].second);
        }
        return v;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends