// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long lon

class Solution{
public:
void solve(ll i, vector<vector<ll>> &v)
{
     if(i == 1) {
          v[i][1] = 1;
          return;
      }
      solve(i - 1, v);
      for(ll j = 1; j <= i; ++j) {
          v[i][j] = (v[i - 1][j] + v[i - 1][j - 1]) % 1000000007;
      }
}
   vector<ll> nthRowOfPascalTriangle(int n) {
       // code here
       vector<vector<ll>> v(n+1,vector<ll>(n+1));
       solve(n,v);
       vector<ll>v1 = v[n];
       v1.erase(v1.begin());
       return v1;
   }
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends