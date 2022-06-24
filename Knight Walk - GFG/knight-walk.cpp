// { Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution {
public:

	int dx[8] = {-1,-2,-2,-1,1,2, 2, 1};
    int dy[8] = {2,1,-1,-2,2,1, -1, -2};
    
    bool isvalid(int x, int y, int n)
    {
        if(x >= 1 && y>=1 and x<=n and y<=n)
        {
            return true;
        }
        
        return false;
    }
    
	int minStepToReachTarget(vector<int>&k, vector<int>&t, int n){
	    
	    
	    int vis[n+1][n+1] = {0};
	    
	    queue<vector<int>> q;
	    
	    q.push(k);
	    
	    vis[k[0]][k[1]] = 1;
	    
	    int ans = 0;
	    
	    while(!q.empty())
	    {
	        
	        int s = q.size();
	        
	        while(s--)
	        {
	            auto x = q.front();
	            q.pop();
	            
	            if(x[0] == t[0] && x[1] == t[1])
	            {
	                return ans;
	            }
	            
	            vis[x[0]][x[1]] = 1;
	            
	            for(int i=0; i<8; i++)
	            {
	                int o = dx[i] + x[0];
	                int p = dy[i] + x[1];
	                
	                if(isvalid(o,p,n) && !vis[o][p])
	                {
	                    q.push({o,p});
	                    vis[o][p] = 1;
	                }
	            }
	        }
	        
	        ans++;
	    }
	    
	    return ans;
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