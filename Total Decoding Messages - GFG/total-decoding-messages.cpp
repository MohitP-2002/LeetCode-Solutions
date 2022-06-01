// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
	int m=1e9+7;
	    int solver(int i, string& s, int mem[]){
        if(mem[i]!=-1) return mem[i]%m;
        if(i==s.length()) return mem[i]=1;
        if(s[i]=='0') return mem[i]=0;
        int res=solver(i+1, s, mem)%m;
        if((i<s.length()-1) && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
           res+=solver(i+2,s,mem)%m;
        }
        return mem[i]=res%m;
    }
		int CountWays(string s){
		    // Code here
		    int mem[s.length()+1];
        memset(mem,-1,sizeof(mem));
        mem[s.length()]=1;
        return s.empty()?0:solver(0,s,mem);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends