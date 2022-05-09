// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solver(vector<vector<int>> &m, int r, int c, string s, vector<string>& v){
        if(r<0 || c<0 || r>=m.size()||c>=m.size() || m[r][c]==0){
            return ;
        }
        if(r==m.size()-1 && c==m.size()-1){
            v.push_back(s);
            return ;
        }
        m[r][c]=0;
        solver(m,r+1,c,s+'D',v);
        solver(m,r-1,c,s+'U',v);
        solver(m,r,c+1,s+'R',v);
        solver(m,r,c-1,s+'L',v);
        m[r][c]=1;
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> v;
        string s="";
        solver(m,0,0,s,v);
        return v;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends