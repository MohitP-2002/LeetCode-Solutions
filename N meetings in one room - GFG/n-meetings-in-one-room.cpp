// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int a[], int b[], int n)
    {
        // Your code here
        vector<vector<int>> A(n, vector<int>(2));
        for(int i=0;i<n;i++){
            A[i][0]=a[i];
            A[i][1]=b[i];
        }
        sort(A.begin(),A.end());
        vector<vector<int>> v;
        v.push_back(A[0]);
        for(int i=1;i<n;i++){
            if(v.back()[1]>=A[i][0]){
                v.back()[1]=min(v.back()[1], A[i][1]);
            }
            else{
                v.push_back(A[i]);
            }
        }
        return v.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends