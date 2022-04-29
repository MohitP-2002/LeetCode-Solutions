class Solution {
public:
    
    bool helper(vector<int>adj[],int n,vector<int> indegree,vector<int>&ans){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            for(auto i:adj[cur]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
            ans.push_back(cur);
            count++;
        }
        if(count!=n) return false;
        return true;
    }
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> adj[n], ans;
        vector<int> indegree(n,0);
        for(int i=0;i<p.size();i++){
            adj[p[i][1]].push_back(p[i][0]);
            indegree[p[i][0]]+=1;
        }
        if(helper(adj,n,indegree,ans)==false){
            ans.clear();
            return ans;
        }
        return ans;
    }
};