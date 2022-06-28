// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
  long long gc_d(int a , int b){
      return (b==0)?a:gc_d(b,a%b);
  }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        vector<long long> v;
        long long  gcd=gc_d(A,B);
        long long lcm = (A*B)/gcd;
        v.push_back(lcm);
        v.push_back(gcd);
        return v;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends