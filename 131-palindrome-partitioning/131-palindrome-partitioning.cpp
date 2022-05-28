class Solution {
public:
    bool isPalindrome(int i, int j, string& str){
        while(i<j){
            if(str[i]!=str[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void fun(int i, int n, string& str,vector<string>& res, vector<vector<string>>& ans){
        //base case 
        if(i>=n && res.size()>0){
            ans.push_back(res);
        }
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,str)){
                res.push_back(str.substr(i,j-i+1));
                //recurse
                fun(j+1,n,str,res,ans);
                //backtrack
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n =s.length();
        vector<vector<string>> ans;
        vector<string> res;
        fun(0,n,s,res,ans);
        return ans;
    }
};