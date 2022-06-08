// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int smallestSumSubarray(vector<int>& a){
      //Code here
      int p=0;
      for(int i=0;i<a.size();i++){
          if(a[i]>0) p++;
      }
      if(p==a.size()) return *min_element(a.begin(),a.end());
      int cur=0,sum=INT_MAX;
      for(int i=0;i<a.size();i++){
          cur+=a[i];
          sum=min(sum, cur);
          if(cur>0) cur=0;
      }
      return sum;
  }
};


// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        
        int ans = ob.smallestSumSubarray(a);
        
        cout<<ans<<endl;
    }
}  // } Driver Code Ends