// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void TOH(int src, int dest, int helper, vector<pair<int,int>>& v, int n){
        if(n==1) {
            v.push_back({src,dest});
            return;
        }
        TOH(src,helper,dest,v,n-1);
        v.push_back({src,dest});
        TOH(helper, dest,src, v, n-1);
    }
    vector<int> shiftPile(int N, int n){
        // code here
        vector<pair<int,int>> v;
        TOH(1,3,2,v,N);
        vector<int> ans;
        ans.push_back(v[n-1].first);
        ans.push_back(v[n-1].second);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends