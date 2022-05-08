class Solution {
public:
    void solver(vector<int>& c, int target, vector<int>& cur, int sum, int index, vector<vector<int>>& ans){
        if(sum> target){
            return ;
        }
        if(sum==target){
            ans.push_back(cur);
            return;
        }
        for(int i=index; i<c.size();i++){
            sum+=c[i];
            cur.push_back(c[i]);
            solver(c,target, cur, sum, i, ans);
            cur.pop_back();
            sum-=c[i];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        solver(candidates, target, cur, 0,0, ans);
        return ans;
    }
};