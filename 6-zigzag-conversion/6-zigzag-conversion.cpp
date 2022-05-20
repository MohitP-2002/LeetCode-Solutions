class Solution {
public:
    string convert(string s, int n) {
        if(n==1) return s;
        vector<string> res(n);
        int row=0;
        int increase=-1;
        for(int i=0;i<s.size();i++){
            if(i%(n-1)==0) increase*=-1;
            res[row].push_back(s[i]);
            row+=increase;
        }
        string ans="";
        for(auto i:res){
            ans+=i;
        }
        return ans;
    }
};