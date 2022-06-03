// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> arr)
    {
        // code here
         int result = arr[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = (j == 0) ? 0 : arr[i - 1][j - 1];
                int y = arr[i - 1][j];
                int z = (j == n - 1) ? 0 : arr[i - 1][j + 1];
                arr[i][j] += max({ x, y, z });
                if (i == n - 1)
                    result = max(result, arr[i][j]);
            }
        }
        return result;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends