// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int n, int d) {
	    // Code here
	    int x=n/d;
	    int y=n%d;
	    string s="";
	    s+=to_string(x);
	    if(y==0) return s;
	    s+='.';
	    string dec="";
	    unordered_map<int,int> m;
	    m[y]=0;
	    y=y*10;
	    int i=1;
	    while(y>0){
	        int a=y/d;
	        int b=y%d;
	        dec+=to_string(a);
	        if(m.find(b)!=m.end()){
	            int index=m[b];
	            dec.insert(index,"(");
	            dec+=")";
	            break;
	        }
	        else{
    	        m[b]=i;
    	        i++;
    	        y=b*10;
	        }
	    }
	    s+=dec;
	    return s;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends