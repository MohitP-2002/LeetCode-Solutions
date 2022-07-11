class Solution {
public:
    int minAddToMakeValid(string s) {
        int bal=0, ans=0;
        for(int i=0;i<s.length();i++){
            bal+=s[i]=='('?1:-1;
            if(bal==-1){
                ans++;
                bal=0;
            }
        }
        return ans+bal;
    }
};