// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(unordered_set<string> set,string s, string st,int n, int index, vector<string>& v){
        if(index==n){
            v.push_back(st);
            return;
        }
        st+=" ";
        for(int i=index;i<n;i++){
            if(set.find(s.substr(index,i+1-index))!=set.end()){
                solve(set,s, st+s.substr(index,i+1-index),n, i+1, v);
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& wordDict, string s)
    {
        // code here
        unordered_set<string> set;
        vector<string> v;
        for(auto i:wordDict){
            set.insert(i);
        }
        if(set.size()==0) return v;
        for(int i=0;i<s.size();i++){
            if(set.find(s.substr(0,i+1))!=set.end()){
                solve(set,s, s.substr(0,i+1),s.size(), i+1, v);
            }
        }
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends