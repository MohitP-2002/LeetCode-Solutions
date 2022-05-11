class Solution {
public:
    void solver(vector<string>& res , int n ,int m, string s){
        if(m==0 && n==0){
            res.push_back(s);
            return ;
        }
        if(m>0) solver(res,n,m-1,s+")");
        if(n>0) solver(res,n-1, m+1, s+"(");
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solver(res,n,0,"");
        return res;
    }
};