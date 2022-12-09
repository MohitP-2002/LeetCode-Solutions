//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

long long numOfWays(int n, int m);

int main() {
    // code
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        cout << numOfWays(n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends


//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.
long long numOfWays(int n, int m){
    // write code here
    const long long mod = 1e9 + 7;
    long long dir[8][2] = {
        {-2,1}, {-2,-1}, {-1,2}, {-1,-2}, {1,2}, {1,-2}, {2,1}, {2,-1}
    };
    long long sq = n*m, ans = 0;
    for (auto i = 1; i <= n; i++){
        for (auto j = 1; j <= m; j++){
            long long count = 0;
            for (auto k = 0; k < 8; k++){
                long long x = dir[k][0] + i, y = dir[k][1] + j;
                if (x >= 1 && x <= n && y >= 1 && y <= m){
                    count++;
                }
            }
            ans += sq - count - 1, ans %= mod;
        }
    }
    return ans;
}