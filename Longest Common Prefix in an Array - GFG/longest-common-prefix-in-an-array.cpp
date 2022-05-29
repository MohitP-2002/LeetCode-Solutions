// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string minstr=arr[0];
        for(int i=0;i<N;i++){
            if(minstr.compare(arr[i])>0)minstr=arr[i];
        }
        for(int i=0;i<N;i++){
            string s=arr[i];
            for(int k=0;k<s.length();k++){
                if(s[k]!=minstr[k]){
                    minstr=minstr.substr(0,k);
                    break;
                }
            }
        }
        if(minstr=="") return "-1";
        return minstr;
    }
};

// { Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
  // } Driver Code Ends