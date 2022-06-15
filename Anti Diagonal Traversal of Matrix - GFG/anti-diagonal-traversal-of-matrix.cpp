// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> A) 
    {
        // Code here
        vector<int> ans;
        int x=0,y=0;
        int n=A.size();
        int j=0;
        while(j<n){
            for(int i=0;i<n;i++){
                int x=j,y=i;
                while(x<=i && y>=j){
                    if(A[x][y]==-1) {
                        x++;
                        y--;
                        continue;
                    }
                    ans.push_back(A[x][y]);
                    A[x][y]=-1;
                    x++;
                    y--;
                }
            }
            j++;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends