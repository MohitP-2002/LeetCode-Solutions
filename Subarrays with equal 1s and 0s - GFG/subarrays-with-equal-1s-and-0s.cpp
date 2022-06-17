// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
  public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //Your code here
        long long int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0) arr[i]=-1;
        }
        int presum=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            presum+=arr[i];
            if(presum==0) count++;
            if(m.find(presum)!=m.end()){
                count+=m[presum];
            }
            m[presum]++;
        }
        return count;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution obj;
	cout<< obj.countSubarrWithEqualZeroAndOne(arr, n)<<"\n";
	}
	return 0;
}
  // } Driver Code Ends