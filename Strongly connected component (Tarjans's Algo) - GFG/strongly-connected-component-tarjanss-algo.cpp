// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(int u,vector<int> &disc,vector<int> &low,vector<bool> &present,stack<int> &st,vector<int>adj[],vector<vector<int>>&ans)
    {
       static int time=0;
       disc[u]=time;
       low[u]=time;
       time++;
       st.push(u);
       present[u]=true;
       for(int v:adj[u])
       {
           if(disc[v]==-1) // if v is not visited
          { dfs(v,disc,low,present,st,adj,ans);
              low[u]=min(low[u],low[v]);
          }
          else if(present[v]==true) /// backedge case
          low[u]=min(low[u],disc[v]);
           
       }
       int w=-1;
       if(low[u]==disc[u]) // u is head of SCC 
       {
           vector<int> comp;
           while(w!=u)
           {
               w=st.top();
               comp.push_back(st.top());
               present[st.top()]=false;
               st.pop();
           }
           sort(comp.begin(),comp.end());
           ans.push_back(comp);
       }
       
    }
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        vector<int> disc(V,-1),low(V,-1);
        vector<bool>present(V,false);
        stack<int> st;
        vector<vector<int>> ans;
        for(int i=0 ;i<V;i++)
        {
           if(disc[i]==-1)
           dfs(i,disc,low,present,st,adj,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends