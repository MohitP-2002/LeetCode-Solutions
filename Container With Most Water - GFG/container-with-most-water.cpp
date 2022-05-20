// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long height[], int len)
{
    // Your code goes here
    long long  ans=0;
        long long i=0,j=len-1;
        while(i<j){
            long long  res=(min(height[i],height[j]))*(j-i);
            ans=max(ans,res);
            if(height[i]>height[j]) j--;
            else i++;
        }
        return ans;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends