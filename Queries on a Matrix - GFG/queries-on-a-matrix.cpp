// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> solveQueries(int n, vector<vector<int>> Queries) {
        // Code here
        vector<vector<int>> ret(n, vector<int>(n));

        for (auto &q : Queries)
        {
            for (int r = q[0]; r <= q[2]; ++r)
            {
                ++ ret[r][q[1]];
                
                if (q[3] < n - 1)
                    -- ret[r][q[3] + 1];
            }
        }
        
        for (int i = 0; i < n; ++i)
            for (int j = 1; j < n; ++j)
                ret[i][j] += ret[i][j - 1];
        
        return ret;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, q;
        cin >> n >> q;
        vector<vector<int>> Queries;
        for (int i = 0; i < q; i++) {
            vector<int> cur(4);
            for (int j = 0; j < 4; j++) cin >> cur[j];
            Queries.push_back(cur);
        }
        Solution obj;
        vector<vector<int>> ans = obj.solveQueries(n, Queries);
        for (auto i : ans) {
            for (auto j : i) cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}  // } Driver Code Ends