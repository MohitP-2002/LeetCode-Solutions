// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
bool dfs(int v, vector<int> adj[],bool vis[],bool b[]){
        if(vis[v] == false)
        {
            vis[v]=true;
            b[v]=true;
            for(auto i:adj[v]){
                if(!vis[i] && dfs(i,adj,vis,b))
                return true;
                if(b[i]==true)return true;
            }
        }
        b[v]=false;
        return false;
    }
        
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        bool vis[V],b[V];
        for(int i=0;i<V;i++){
           vis[i]=false;
           b[i]=false;
        }
        for(int i=0;i<V;i++){
            if(dfs(i,adj,vis,b)) return true;
        }
        return false;
    }
	bool isPossible(int n, vector<pair<int, int> >& p) {
	    // Code here
        vector<int> adj[n+1];
        for(int i=0;i<p.size();i++){
            adj[p[i].first].push_back(p[i].second);
        }
        
        if(isCyclic(n,adj)==true) return false;
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends