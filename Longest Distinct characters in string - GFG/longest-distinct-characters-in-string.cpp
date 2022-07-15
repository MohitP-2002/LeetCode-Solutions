// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    if(S=="") return 0;
    int n = S.length(), len=0;
    vector<int> count(26,0);
    int i=0,j=0;
    while(j<n){
        if(count[S[j]-'a'] > 0){
            len = max(len, j-i);
            while(count[S[j]-'a'] > 0){
                count[S[i]-'a']--;
                i++;
            }
        }
        count[S[j]-'a']++;
        j++;
    }
    len = max(len, j-i);
    return len;
}