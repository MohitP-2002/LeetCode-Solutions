// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int CountPS(char S[], int N);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        char S[N+1];
        cin>>S;
        cout<<CountPS(S,N)<<endl;
    }
    return 0;
}

// } Driver Code Ends


void solver(int i, int j, char S[], int n, int& count){
    while(i>=0 && j<n && S[i]==S[j]){
        count++;
        i--;
        j++;
    }
}
int CountPS(char S[], int N)
{
    //code here
    if(N==0) return 0;
    int count=0;
    for(int i=0;i<N;i++){
        solver(i,i,S,N,count);
        solver(i,i+1,S,N,count);
    }
    return count-N;
}