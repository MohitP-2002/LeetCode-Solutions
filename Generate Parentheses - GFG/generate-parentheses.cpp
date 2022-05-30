// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void backtrack(vector<string>& res, int m ,int n, string s){
        if(m==0 && n==0) {
            res.push_back(s);
            return ;
        }
        if(m>0)backtrack(res,m-1,n,s+")");
        if(n>0)backtrack(res,m+1,n-1,s+"(");
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> res;
        backtrack(res,0,n,"");
        return res;
    }
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends