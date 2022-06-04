// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n =nums.size();
	    if(n==0) return 0;
	    vector<int> inc(n,0);
	    vector<int> dec(n,0);
	    //longest increasing subsequence
	    inc[0]=1;
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(nums[i]>nums[j]){
	                inc[i]=max(inc[i],inc[j]);
	            }
	        }
	        inc[i]++;
	    }
	    //longest decreasing subsequence
	    dec[n-1]=1;
	    for(int i=n-2;i>=0;i--){
	        for(int j=n-1;j>i;j--){
	            if(nums[i]>nums[j]){
	                dec[i]=max(dec[i],dec[j]);
	            }
	        }
	        dec[i]++;
	    }
	    int lbs=1;
	    for(int i=0;i<n;i++){
	        lbs=max(lbs,inc[i]+dec[i]-1);
	    }
        return lbs;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends