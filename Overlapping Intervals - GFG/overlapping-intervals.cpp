// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
 bool isOverlap(vector<int>a,vector<int > b){
           return a[0] <= b[1] && b[0] <= a[1] ;
      }
      
      vector<int> mergeInt(vector<int>a,vector<int > b){
          vector<int> k;
          k.push_back(min(a[0],b[0]));
          k.push_back(max(a[1],b[1]));
          return k;
      }

    vector<vector<int>> overlappedInterval(vector<vector<int>>& v) {
         // Code here
         sort(v.begin(),v.end());
         vector<vector<int>> ans;
        for(int i=0;i<v.size()-1;i++){
            if(isOverlap(v[i],v[i+1])){
                v[i+1]=mergeInt(v[i],v[i+1]);
            }
            else{
                ans.push_back(v[i]);
            }
        }
        ans.push_back(v[v.size()-1]);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends