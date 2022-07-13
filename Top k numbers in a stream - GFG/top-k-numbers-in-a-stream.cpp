// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
#define ppi pair<int,int>
class Solution
{
  public:   
        static bool comp(ppi a, ppi b){
            return a.first==b.first?a.second < b.second:a.first > b.first;
        }
    vector<int> kTop(int a[], int n, int k) 
    { 
        //code here.
        vector<int> res;
        unordered_map<int ,int> m;
        vector<ppi> v;
        for(int i=0;i<n;i++){
            m[a[i]]++;
            v.clear();
            for(auto i:m){
                v.push_back({i.second,i.first});
            }
            sort(v.begin(), v.end(), comp);
            if(v.size()<k){
                for(auto i:v) res.push_back(i.second);
            }
            else{
                for(int i=0;i<k;i++){
                    res.push_back(v[i].second);
                }
            }
        }
        return res;
    }
};


// { Driver Code Starts.

int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    long long k;
	    cin >> n;
	    cin >> k;
	    int a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	    }
	        Solution ob;
	        vector<int> ans;
	        ans=ob.kTop(a,n,k);
	        for(int i=0;i<ans.size();i++)
	        {
	        cout<<ans[i];
	        cout<<" ";
	        }
	        cout<<'\n';
	    }
	return 0;
}
  // } Driver Code Ends