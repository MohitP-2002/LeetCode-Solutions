// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            string  p="";
            int count=0;
            for(int  i=0;i<s.length();i++){
                if(((int)s[i] < 48||(int)s[i] > 57) && s[i]!='.') return false;
                if(s[i]=='.' || i==s.length()-1){
                    count++;
                    if(i==s.length()-1){count--;
                        p+=s[i];}
                    if(p=="" || p.length()>3) return false;
                    if(p[0]=='0' && p.length()>1) return false;
                    if(!(stoi(p)>=0 && stoi(p)<=255)) return false;
                    p="";
                }
                else{
                    p+=s[i];
                }
            }
            if(count!=3) return false;
            return true;
        }
};

// { Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}  // } Driver Code Ends