// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    string s="";
		    unordered_map<char,int> m;
		    for(int i=0;i<A.length();i++){
		        m[A[i]]++;
		        if(m[A[i]]==1){
		            q.push(A[i]);
		        }
		        while(!q.empty()){
		            if(m[q.front()]==1) break;
		            q.pop();
		        }
		        s+=(q.empty()?'#':q.front());
		    }
		    return s;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends