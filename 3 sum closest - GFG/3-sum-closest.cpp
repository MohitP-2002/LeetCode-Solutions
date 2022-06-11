// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int arr[], int n, int target)
    {
        // code 
            int ans=arr[0]+arr[1]+arr[2];
            sort(arr, arr+n);
            for(int k=0;k<n;k++){
                int i=k+1,j=n-1;
                while(i<j){
                    int sum = arr[i]+arr[j]+arr[k];
                    if(i==k){ i++;
                            continue;}
                    if(j==k) {j--;
                             continue;}
                    if(sum==target && j!=k && i!=k){
                        return target;
                    }
                    if(abs(target-sum)<abs(target-ans)) {
                        ans = sum;
                    }
                    else if(sum>target){
                        j--;
                    }
                    else {
                        i++;
                    }
                }
            }
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
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Ends