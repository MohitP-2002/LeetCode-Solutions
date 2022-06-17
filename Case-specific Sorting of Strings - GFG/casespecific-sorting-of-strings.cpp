// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        // your code here
        string uc="",lc="";
        for(int i=0;i<n;i++){
            if(str[i]>='a'&&str[i]<='z') lc+=str[i];
            else uc+=str[i];
        }
        sort(uc.begin(),uc.end());
        sort(lc.begin(),lc.end());
        int j=0,k=0;
        for(int i=0;i<n;i++){
            if(str[i]>='a'&&str[i]<='z') {
                str[i]=lc[j];
                j++;
            }
            else{
                str[i]=uc[k];
                k++;
            }
        }
        return str;
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
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}  // } Driver Code Ends