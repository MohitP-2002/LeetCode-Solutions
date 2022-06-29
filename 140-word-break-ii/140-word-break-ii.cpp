class Solution {
public:
    void solve(unordered_set<string> set,string s, string st,int n, int index, vector<string>& v){
        if(index==n){
            v.push_back(st);
            return;
        }
        st+=" ";
        for(int i=index;i<n;i++){
            if(set.find(s.substr(index,i+1-index))!=set.end()){
                solve(set,s, st+s.substr(index,i+1-index),n, i+1, v);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;
        vector<string> v;
        for(auto i:wordDict){
            set.insert(i);
        }
        if(set.size()==0) return v;
        for(int i=0;i<s.size();i++){
            if(set.find(s.substr(0,i+1))!=set.end()){
                solve(set,s, s.substr(0,i+1),s.size(), i+1, v);
            }
        }
        return v;
    }
};