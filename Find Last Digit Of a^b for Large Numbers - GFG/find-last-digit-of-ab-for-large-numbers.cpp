// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int Modulo(int a , string b){
        int mod=0;
        for(int i=0;i<b.length();i++){
            mod = (mod*10 + b[i]-'0')%a;
        }
        return mod;
    }
    int getLastDigit(string a, string b) {
        // code here
        int len_a = a.length(), len_b = b.length();
        if (len_a == 1 && len_b == 1 && b[0] == '0' && a[0] == '0')
            return 1;
        if (len_b == 1 && b[0] == '0')
            return 1;
        if (len_a == 1 && a[0] == '0')
            return 0;
        int exp = Modulo(4,b)==0?4:Modulo(4,b);
        int ldigit = pow(a[len_a-1]-'0', exp);
        return ldigit%10;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a,b;
        
        cin>>a>>b;

        Solution ob;
        cout << ob.getLastDigit(a,b) << endl;
    }
    return 0;
}  // } Driver Code Ends