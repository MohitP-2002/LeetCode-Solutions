// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    static bool comp(pair<int,int>& p1, pair<int,int>& p2){
        if(p1.first==p2.first) return p1.second<p2.second;
        return p1.first> p2.first;
    }
    vector<int> sortByFreq(int arr[],int n)
    {
        //Your code here
        vector<int> ans;
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        vector<pair<int,int>> v;
        for(auto i:m){
            v.push_back(make_pair(i.second,i.first));
        }
        sort(v.begin(),v.end(), comp);
        for(auto i:v){
            for(int k=0;k<i.first;k++)
            ans.push_back(i.second);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}

  // } Driver Code Ends