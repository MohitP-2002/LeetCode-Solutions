// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

// arr[]: Input array
// n: Number of elements in the array
// k: Find a pair with sum less than k
pair<int, int> Max_Sum(int arr[], int n, int k) {
    // return the pair
    pair<int, int> v({0,0});
    sort(arr, arr+n);
    int i=0,j=n-1;
    while(i<j){
        int sum=arr[i]+arr[j];
        if(sum < k){
            if(sum > v.first+v.second){
                v.first=arr[i];
                v.second=arr[j];
            }
            i++;
        }
        else j--;
    }
    return v;
}


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n + 5];
        for (int i = 0; i < n; i++) cin >> arr[i];
        pair<int, int> p = Max_Sum(arr, n, k);
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
  // } Driver Code Ends