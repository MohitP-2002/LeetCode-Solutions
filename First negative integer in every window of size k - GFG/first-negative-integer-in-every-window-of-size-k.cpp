// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends



vector<long long> printFirstNegativeInteger(long long int A[],long long int N,long long int K) {
    vector<long long> ans;
           queue<int> q;
           for(int i=0;i<K;i++)
           {
               if(A[i]<0)
               {
                   q.push(i);
               }
           }
           if(q.empty()) ans.push_back(0);
           else ans.push_back(A[q.front()]);       
           for(int i=1;i<=N-K;i++)
           {
               if(A[K+i-1]<0) q.push(K+i-1);
               while(!q.empty())
               {
                   int j = q.front();
                   if(j>=i and j<=K+i-1)
                   {
                       ans.push_back(A[j]);
                       break;
                   }
                   else
                   {
                       q.pop();
                   }
               }
               if(q.empty())ans.push_back(0);
           }
           
           return ans;
 }