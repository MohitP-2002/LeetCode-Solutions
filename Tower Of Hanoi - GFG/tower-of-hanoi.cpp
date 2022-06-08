// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    int count=0;
void solver(int n ,int src, int help, int dest){
    if(n==1){
        
    cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<"\n";
        count++;
        return;
    }
    solver(n-1,src,dest,help);
    cout<<"move disk "<<n<<" from rod "<<src<<" to rod "<<dest<<"\n";
    count++;
    solver(n-1, help, src, dest);

}
long long toh(int N, int from, int to, int aux) {
    //Your code here
     count=0;
    solver(N, from, aux, to);
    return count;
}
};

// { Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.  // } Driver Code Ends