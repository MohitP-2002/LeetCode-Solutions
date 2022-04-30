// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int arr[], int n, int x)
    {
        //Your Code Here
        sort(arr,arr+n);
    for(int k=0;k<n;k++){
        int i=0,j=n-1;
	    while(i<j){
	        if(arr[i]+arr[j]+arr[k]==x && i!=j && j!=k) return true;
	        else if(arr[i]+arr[j]+arr[k]>x)j--;
	        else i++;
	    }
    }
    
	    return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends