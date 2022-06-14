// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int longestUniqueSubsttr(string s){
        //code
        vector<int>c(26,0);
        int i=0, j=0, n=s.length();
        int ans=0;
        while(j<n){
            if(c[s[j]-'a']!=0){
                c[s[i]-'a']--;
                ans=max(ans,(j-i));
                i++;
            }
            else{
                c[s[j]-'a']++;
                j++;
            }
        }
        ans=max(ans,j-i);
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		Solution ob;
		cout<<ob.longestUniqueSubsttr(str)<<endl;
	}
	return 0;
}  // } Driver Code Ends