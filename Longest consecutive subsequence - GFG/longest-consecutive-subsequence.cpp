// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      set<int> s;
      for(int i=0;i<n;i++) s.insert(arr[i]);
      int k=0;
      for(auto i:s) arr[k++]=i;
      for(int i=k;i<n;i++){
          arr[i]=INT_MIN;
      }
      int m=INT_MIN,c=1;
      for(int i=1;i<n;i++){
          if(arr[i]-1==arr[i-1]){
              c++;
          }
          else{
              m=max(m,c);
              c=1;
          }
      }
      m=max(m,c);
      return m;
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends