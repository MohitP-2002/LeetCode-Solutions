// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    void sort(int arr[], int n)
    {
        // your code here
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        int k=0;
        for(auto i:m){
            for(int  p=0;p<i.second;p++){
                arr[k++]=i.first;
            }
        }
    }
};

// { Driver Code Starts.
void print(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


// Driver program to test above functions
int main()
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int arr[n];
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		Solution ob;
		ob.sort (arr, n);
		print (arr, n);
		cout << endl;
	}
}



  // } Driver Code Ends