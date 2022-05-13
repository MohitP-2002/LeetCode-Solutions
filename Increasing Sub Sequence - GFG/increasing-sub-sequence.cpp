// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int maxLength(string a)
    {
        // code here
        int n = a.length();
        vector<int> ans;
       for(int i=0;i<n;i++){
           auto it = lower_bound(ans.begin(),ans.end(), a[i]);
           if(it==ans.end()) ans.push_back(a[i]);
           else *it=a[i];
       }
       return ans.size();
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution ob;
        cout << ob.maxLength(S) << endl;
    }
    return 0; 
}  // } Driver Code Ends