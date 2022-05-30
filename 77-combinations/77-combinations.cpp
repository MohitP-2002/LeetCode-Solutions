class Solution {
public:
    vector<vector<int>> v;
    void recursion(int i,int n, int k, vector<int>& res){
        if(k==0){
            v.push_back(res);
            return;
        }
        for(int j=i;j<=n;j++){
            res.push_back(j);
            recursion(j+1,n,k-1,res);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n),res;
        recursion(1,n,k,res);
        return v;
    }
};