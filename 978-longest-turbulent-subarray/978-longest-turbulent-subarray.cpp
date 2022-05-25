class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        int ans=INT_MIN;
        vector<int> dp_g(n,1), dp_s(n,1);
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                dp_g[i]=dp_s[i+1]+1;
            }
            else if(arr[i]<arr[i+1]){
                dp_s[i]=dp_g[i+1]+1;
            }
        }
        for(int i=0;i<n;i++){
            ans=max({dp_g[i],dp_s[i],ans});
        }
        return ans;
    }
};