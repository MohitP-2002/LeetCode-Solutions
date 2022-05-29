// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
          map<int,int> set;
      int sum=0,mx=0;
      set[0]=0;
      for(int i=0;i<n;i++)
      {
          sum+=A[i];
          
          if (set.find(sum)!=set.end() )  
          mx=max(mx,i-set.at(sum)+1); // storing maximum from the set. 
          else                              
          set[sum]=i+1;
      }
      return mx;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends