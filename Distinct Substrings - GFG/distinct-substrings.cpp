// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int fun(string s);

int main() {
    int tt;
    string s;
    cin >> tt;
    while (tt--) {
        cin >> s;
        cout<<fun(s)<<endl;
        
    }
    return 0;
}// } Driver Code Ends


int fun(string s)
{
    //code here
    set<string> st;
    string p="";
    p+=s[0];
    for(int i=1;i<s.length();i++){
        p+=s[i];
        st.insert(p);
        // cout<<p<<" ";
        p="";
        p+=s[i];
    }
    return st.size();
}