// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:
	string removeDuplicates(string str) {
	    // code herez
	    string ans="";
	    int c[200];
	    for(auto i:str){
	        c[(int)i]=1;   
	    }
	    for(int i=0;i<str.length();i++){
	        if(c[(int)(str[i])]==1){
	            ans+=str[i];
	            c[(int)(str[i])]=0;
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends