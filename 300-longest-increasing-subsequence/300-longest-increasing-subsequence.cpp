class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        vector<int> ans(n+1,1);
       for(int i=0;i<n;i++){
           for(int j=0;j<i;j++){
               if(a[i]>a[j])
               ans[i]=max(ans[i],1+ans[j]);
           }
       }
       int max_output=0;
        for(auto i:ans){
            max_output=max(max_output,i);
        }
        return max_output;
    }
};