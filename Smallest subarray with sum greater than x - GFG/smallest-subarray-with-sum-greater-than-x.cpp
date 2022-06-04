// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int nums[], int n, int target)
    {
        // Your code goes here   
        int len=INT_MAX;
        int sum=0;
        int i=0,j=0;
        while(j<n){
            sum+=nums[j++];
            while(sum>target){
                len=min(len,j-i);
                sum-=nums[i++];
            }
        }
        return len;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends