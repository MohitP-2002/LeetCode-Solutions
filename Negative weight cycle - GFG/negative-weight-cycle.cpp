// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    const int INF = 0xffffff;
        vector<int> D(n, INF);
        int f = 1;
        for (int v = 0; v < n && f; v++) {
            f = 0;
            for (auto& e: edges)
                if (D[e[1]] > D[e[0]] + e[2]) {
                    D[e[1]] = D[e[0]] + e[2];
                    f = 1;
                }
        }
        return f;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends