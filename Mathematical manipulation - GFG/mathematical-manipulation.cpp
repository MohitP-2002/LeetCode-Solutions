// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:

	int CommonFactor(int n){
	    // Code here
	    int count=0;
	    for(int i=2;i<=n;i++){
	        if(n%i==0) count++;
	        else if(__gcd(i,n)!=1) count++;
	    }
	    return count;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution obj;
		int ans = obj.CommonFactor(n);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends