// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int ok(int m, int n, int x){
      int ret = 0;
      for(int i = 1; i <= n; i++){
         int temp = min(x / i, m);
         ret += temp;
      }
      return ret;
   }

    int KthSmallest(int m, int n, int k) {
        //Write your code here
         int ret = -1;
      int low = 1;
      int high = m * n ;
      while(low <= high){
         int mid = low + (high - low)/ 2;
         int cnt = ok(m, n, mid);
         if(cnt >= k){
            high = mid - 1;
            ret = mid;
         }else low = mid + 1;
      }
      return ret;
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int m, n, k;
	    cin >> m >> n >> k;
	    Solution ob;
	    int ans = ob.KthSmallest(m, n, k);
	    cout << ans << endl;
	}
	return 0;
}
  // } Driver Code Ends