// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int nums[], int n) {
	    // code here
	    int sorted[n];
	    for(int i=0;i<n;i++) sorted[i]=nums[i];
        int i=0, j=n-1;
        sort(sorted,sorted+n);
        while(i<n && nums[i]==sorted[i]){
            i++;
        }
        while(j>i && nums[j]==sorted[j]) j--;
        vector<int> v;
        if(n==1) {
            v.push_back(0);
            v.push_back(0);
            return v;
        }
        v.push_back(i);
        v.push_back(j);
        return v;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends