// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string t)
    {
        // Your code here
        int m = s.length();
        int n = t.length();
        vector<int>map(128,0);
        for(auto i:t){
            map[i]++;
        }
        int counter=t.length();
        int start=0, end=0, minLen=INT_MAX, minStart=0;
        while(end<m){
            if(map[s[end]]>0) counter--;
            map[s[end]]--;
            end++;
            while(counter==0){
                if(end-start<minLen){
                    minLen=end-start;
                    minStart=start;
                }
                map[s[start]]++;
                if(map[s[start]]>0) counter++;
                start++;
            }
        }
        if(minLen==INT_MAX) return "-1";
        return s.substr(minStart, minLen);
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends