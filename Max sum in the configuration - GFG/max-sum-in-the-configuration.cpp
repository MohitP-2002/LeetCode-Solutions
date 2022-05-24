// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int A[],int N)
{
//Your code here
int ans=0,temp=0,sum=0;
for(int i=0;i<N;i++){
    temp+=A[i]*i;
    sum+=A[i];
}
 ans=temp;
for(int i=0;i<N;i++){
    temp=temp+sum-(N*A[N-i-1]);
    ans=max(ans,temp);
}
return ans;
}