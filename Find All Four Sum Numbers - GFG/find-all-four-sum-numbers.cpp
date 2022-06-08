// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int X) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int check_sum = 0;
        set<vector<int>> ans;
        
        for(int i = 0; i < n - 3; i++) {
            
            for (int j = i + 1; j < n - 2; j++) {
                
                int k = j + 1;
                int l = n - 1;
                
                int min_sum = arr[i] + arr[j] + arr[k] + arr[k + 1];
                int max_sum = arr[i] + arr[j] + arr[n - 2] + arr[n - 1];
                
                if(min_sum <= X && X <= max_sum) {
                
                    while (k < l) {
                        
                        int sum = arr[i] + arr[j] + arr[k] + arr[l];
                        
                        if(sum > X) {
                            l--;
                        } else if (sum == X) {
                            ans.insert({arr[i], arr[j], arr[k], arr[l]});
                            k++;
                        } else {
                            k++;
                        }        
    
                    }
                } else {
                    continue;
                }
                
            }
            
        }
        
        vector<vector<int>>vec;
       for(auto it=ans.begin();it!=ans.end();it++){
           vec.push_back(*it);
       }
       return vec;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends