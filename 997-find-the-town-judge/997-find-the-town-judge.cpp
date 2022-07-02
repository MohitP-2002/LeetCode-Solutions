class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n,0);
        vector<int> adj[n];
        for(auto t:trust){
            adj[t[0]-1].push_back(t[1]-1);
        }
        for(int i=0;i<n;i++){
            for(auto v:adj[i]){
                indegree[v]++;
            }
        }
        bool flag = false;
        int ans=0;
        for(int i=0;i<n;i++){
            // cout<<ans<<" ";
            if(indegree[i]==n-1 && flag==false && adj[i].size()==0){
                ans=i+1;
                flag = true;
            }
            else if(flag && indegree[i]==n-1 ) return -1;
        }
        return ans==0?-1:ans;
    }
};