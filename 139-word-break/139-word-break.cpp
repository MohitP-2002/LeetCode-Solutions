class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        for(auto i:wordDict){
            set.insert(i);
        }
        if(set.size()==0) return false;
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    if(set.find(s.substr(j,i-j))!=set.end()){
                        dp[i]=true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};