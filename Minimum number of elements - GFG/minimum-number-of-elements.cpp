// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
#define MAX 102
	public:
	int countMin(int arr[], int dp[MAX][MAX][MAX], int n, int dec,
                                            int inc, int i)
{
    // If already calculated, return value.
    if (dp[dec][inc][i] != -1)
        return dp[dec][inc][i];
 
    // If whole array is traversed.
    if (i == n)
        return 0;
 
    // calculating by considering element as part of
    // decreasing sequence.
    if (arr[i] < arr[dec])
        dp[dec][inc][i] = countMin(arr, dp, n, i, inc, i + 1);
 
    // calculating by considering element as part of
    // increasing sequence.
    if (arr[i] > arr[inc])
    {
        // If cannot be calculated for decreasing sequence.
        if (dp[dec][inc][i] == -1)
            dp[dec][inc][i] = countMin(arr, dp, n, dec, i, i + 1);
 
        // After considering once by decreasing sequence, now try
        // for increasing sequence.
        else
            dp[dec][inc][i] = min(countMin(arr, dp, n, dec, i, i + 1),
                                                  dp[dec][inc][i]);
    }
 
    // If element cannot be part of any of the sequence.
    if (dp[dec][inc][i] == -1)
        dp[dec][inc][i] = 1 + countMin(arr, dp, n, dec, inc, i + 1);
 
    // After considering element as part of increasing and
    // decreasing sequence trying as not part of any of the
    // sequence.
    else
        dp[dec][inc][i] = min(1 + countMin(arr, dp, n, dec, inc, i + 1),
                                                    dp[dec][inc][i]);
 
    return dp[dec][inc][i];
}
	int minCount(int arr[], int N) 
	{ 
        // Your code goes here 
        
        arr[MAX - 2] = INT_MAX;
    arr[MAX - 1] = INT_MIN;
 
    int dp[MAX][MAX][MAX];
    memset(dp, -1, sizeof dp);
 
    return countMin(arr, dp, N, MAX - 2, MAX - 1, 0);
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minCount(a, n) << "\n";
	     
    }
    return 0;
}


  // } Driver Code Ends