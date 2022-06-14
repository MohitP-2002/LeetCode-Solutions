// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int removals(vector<int>& a, int k){
        //Code here
        sort(a.begin(),a.end());
        int i=0,j=0;
        int n = a.size();
        int count=a.size();
        while(j<n){
            int dif=a[j]-a[i];
            if(dif<=k) {
                count=min(count,(n-(j-i+1)));
                j++;
            }
            else {
                i++;
            }
        }
        return count;
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends