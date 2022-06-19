// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    set<vector<int>>ans;
    
    void generate(vector<int> subset,int i, vector<int> nums){
        
        if(i==nums.size()){
            ans.insert(subset);
            return ;
        }
        
        generate(subset,i+1,nums);
        
        subset.push_back(nums[i]);
        generate(subset,i+1,nums);
        subset.pop_back();
        
    }
    vector<vector<int> > AllSubsets(vector<int> nums, int n)
    {
        // code here 
        vector<int> subset;
        sort(nums.begin(),nums.end());
        generate(subset,0,nums);
        vector<vector<int>> v;
        for(auto i:ans) v.push_back(i);
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends