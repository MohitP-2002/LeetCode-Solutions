// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
long check(long H[], long A[], long mid,
           long N, long M, long L)
{
    // Stores the sum of speed
    long sum = 0;
 
    // Iterate over the range [0, N]
    for (long i = 0; i < N; i++) {
 
        // Find the value of speed
        long speed = mid * A[i] + H[i];
 
        // If the bike is considered
        // to be fast add it in sum
        if (speed >= L) {
            sum += speed;
        }
    }
 
    // Return the resultant sum
    return sum;
}
 
// Function to find the minimum number
// of time required
long buzzTime(long N, long M, long L,
              long H[], long A[])
{
    // Stores the range of Binary Search
    long low = 0, high = 1e10;
 
    // Stores the minimum number of
    // time required
    long ans = 0;
 
    while (high >= low) {
 
        // Find the value of mid
        long mid = low + (high - low) / 2;
 
        // If the mid is the resultant
        // speed required
        if (check(H, A, mid,
                  N, M, L)
            >= M) {
 
            // Update the ans and high
            ans = mid;
            high = mid - 1;
        }
 
        // Otherwise
        else
            low = mid + 1;
    }
 
    // Return the minimum number of hours
    return ans;
}
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long N, M, L;
        cin>>N>>M>>L;
        long H[N], A[N];
        for(long i = 0;i < N;i++) 
            cin>>H[i]>>A[i];
        
        Solution ob;
        cout<<ob.buzzTime(N, M, L, H, A)<<"\n";
    }
    return 0;
}  // } Driver Code Ends