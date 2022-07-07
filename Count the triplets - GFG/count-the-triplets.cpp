// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	int countTriplet(int arr[], int n)
	{
	    // Your code goes here
	    int count=0;
	    sort(arr,arr+n);
	    for(int i=0;i<n;i++){
	        int j=0,k=n-1,target=arr[i];
	        while(j<k){
	            if(j==i){
	                j++;
	                continue;
	            }
	            if(k==i){
	                k--;
	                continue;
	            }
	            if(arr[j]+arr[k]==target){
	                count++;
	                j++;
	                k--;
	            }
	            else if(arr[j]+arr[k]>target) k--;
	            else j++;
	        }
	    }
	    return count;
	}
};

// { Driver Code Starts.


int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        	cin >> arr[i];

        Solution ob;
        cout << ob.countTriplet(arr, n) << "\n";

    }

    return 0;
}  // } Driver Code Ends