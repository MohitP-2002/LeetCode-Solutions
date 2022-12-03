//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

       int maxDist(vector<int> &v) {
        int mini = INT_MAX, maxi = INT_MIN;
    
        for(int x : v) {
            mini = min(mini,x);
            maxi = max(maxi,x);
        }
    
        return maxi-mini;
    }
    
    bool isSafe(int mid, vector<int> &v, int k) {
        int lp = v[0], cows = 1;
    
        for(int i = 1; i < v.size(); i++) {
            if(v[i]-lp >= mid){
                cows++;
                lp = v[i];
                if(cows == k) return true;
            }
        }
        return false;
    }

    int solve(int n, int k, vector<int> &v) {
        int l = 0, h = maxDist(v);
        int ans = 0;
        
        sort(v.begin(), v.end());
        
        while(l <= h) {
            int mid = (l+h)/2;
    
            if(isSafe(mid,v,k)) {
                ans = mid;
                l = mid+1;
            }
            else h = mid-1;
        }
    
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends