// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string S){
		    // Code here
		    int N = pow(2, S.size());
 vector<string> ans;
    // generate each subset one by one
            for (int i = 1; i < N; i++)
            {
                string s="";
                // check every bit of `i`
                for (int j = 0; j < S.size(); j++)
                {
                    // if j'th bit of `i` is set, print `S[j]`
                    if (i & (1 << j)) {
                        s+=S[j];
                    }
                }
                ans.push_back(s);
            }
            sort(ans.begin(),ans.end());
            return ans;
		}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  // } Driver Code Ends