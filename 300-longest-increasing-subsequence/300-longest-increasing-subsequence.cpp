class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> ans;
       for(int i=0;i<n;i++){
           auto it = lower_bound(ans.begin(),ans.end(), a[i]);
           if(it==ans.end()) ans.push_back(a[i]);
           else *it=a[i];
       }
       return ans.size();
    }
};