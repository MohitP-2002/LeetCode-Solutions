// { Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
  public:
   bool isPalin(string &s,int i,int j){
     while(i<j){
         if(s[i]==s[j]){
             i++;
             j--;
         }
         else{
             return 0;
         }
     }
     return true;
 }
   int palindromeSubStrs(string s) {
       // code here
       int n=s.length();
       unordered_set<string> se;
       int count=0;
       for(int i=0;i<n;i++){
           string x="";
           for(int j=i;j<n;j++){
               x+=s[j];
               if(isPalin(s,i,j)){
                   se.insert(x);
               }
           }
       }
       return se.size();
   }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends