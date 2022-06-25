// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    struct TrieNode
    {
        bool isUnique = true;
        int len = 0;
        TrieNode *_tn[26];
        
    };
    void insert(TrieNode* root,string s){
        
        for(char c : s){
            
            if(root->_tn[c-'a']==NULL){
                root->_tn[c-'a'] = new TrieNode();
                
            }else{
                root->_tn[c-'a']->isUnique = false;
            }
            root = root->_tn[c-'a'];
            // cout<<c<<" ";
        }
        // cout<<endl;
    }
    
    string getpre(TrieNode* root,string s){
        string ans = "";
        for(char c:s){
            root = root->_tn[c-'a'];
            ans.push_back(c);
            if(root->isUnique)return ans;
        }
        return ans;
    }
    
    
    vector<string> findPrefixes(string arr[], int n)
    {
        TrieNode* root = new TrieNode();
        for(int i=0;i<n;i++){
            insert(root,arr[i]);
        }
        vector<string> res;
        for(int i=0;i<n;i++){
            res.push_back(getpre(root,arr[i]));
        }
        
        return res;
    }
    
};
// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}
  // } Driver Code Ends