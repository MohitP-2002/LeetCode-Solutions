// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int x, int y, int n){
        if(x<1 || y<1 || x>n || y>n ) return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int N)
	{
	    // Code here
	    queue<pair<vector<int>,int>> q;
	    q.push({k,0});
	    vector<vector<bool>> v(N+1, vector<bool>(N+1, false));
	    int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
	    int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
	    while(!q.empty()){
	        auto cur=q.front();
	        q.pop();
	        if(cur.first[0]==t[0] && cur.first[1]==t[1]) {
	            return cur.second;
	        }
	        for(int i=0;i<8;i++){
	            int x=cur.first[0]+dx[i];
	            int y=cur.first[1]+dy[i];
	            if(isValid(x,y,N) && !v[x][y]){
	                v[x][y]=true;
	                q.push({{x,y},cur.second+1});
	            }
	        }
	    }
	    return -1;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends