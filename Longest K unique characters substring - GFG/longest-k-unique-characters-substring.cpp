// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        // your code here
        vector<int> map(128, 0);
        int counter=0, begin=0, end=0, d=0; 
        bool flag = false;
        while(end<s.size()){
            if(map[s[end++]]++==0) counter++;
            while(counter>k) {if(map[s[begin++]]--==1) counter--;
                flag = true;
            }
            if(counter==k) flag = true;
            d=max(d, end-begin);
        }
        if(flag)
        return d;
        return -1;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends