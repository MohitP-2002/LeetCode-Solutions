// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        set<int> s;
        for(auto i:str) s.insert(i);
        int n = s.size();
        int i=0, j=1, c=1;
        unordered_map<char, int> m;
        m[str[i]]++;
        int ans=INT_MAX;
        while(i<=j && j<str.length()){
            if(c<n){
                if(m[str[j]]==0) c++;
                m[str[j]]++;
                j++;
            }
            else if(c==n){
                ans=min(ans,j-i);
                if(m[str[i]]==1) c--;
                m[str[i]]--;
                i++;
            }
        }
        while(c==n){
            ans=min(ans,j-i);
            if(m[str[i]]==1)c--;
            m[str[i]]--;
            i++;
        }
        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}  // } Driver Code Ends