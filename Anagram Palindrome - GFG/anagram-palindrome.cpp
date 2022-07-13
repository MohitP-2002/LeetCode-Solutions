// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int isPossible (string s);

int main()
{
    int t; cin >> t;
    while (t--)
	{
		string s; cin >> s;
		if (isPossible (s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int isPossible (string S)
{
    // your code here
    vector<int> count(26,0);
    for(auto i:S){
        count[i-'a']++;
    }
    if(S.length()%2==0){
        for(auto i:count){
            if(i%2!=0) return false;
        }
        return true;
    }
    int flag=0;
    for(int i=0;i<26;i++){
        if(count[i]%2!=0 && flag!=0) return false;
        if(count[i]%2!=0) flag=1;
    }
    return  true;
}