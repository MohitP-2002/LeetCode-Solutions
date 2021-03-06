class Solution {
public:
    void backtrack(string s , int i, vector<string>& res){
        //base condition
        if(i==s.size()){
            res.push_back(s);
            return ;
        }
        backtrack(s,i+1,res);
        if(isalpha(s[i])){
            s[i]^=1<<5; // toggling case
            backtrack(s,i+1,res);
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<string > res;
        backtrack(s,0,res);
        return res;
    }
};