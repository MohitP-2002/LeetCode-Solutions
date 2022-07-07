// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        //clockwise
        string s=str1;
        int n = str1.length();
        for(int i=0;i<2;i++){
            int temp=s[n-1];
            for(int i=n-1;i>=0;i--){
                s[i]=s[i-1];
            }
            s[0]=temp;
        }
        if(s.compare(str2)==0) return true;
        for(int i=0;i<2;i++){
            int temp=str1[0];
            for(int i=0;i<n-1;i++){
                str1[i]=str1[i+1];
            }
            str1[n-1]=temp;
        }
        if(str1.compare(str2)==0) return true;
        return false;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends