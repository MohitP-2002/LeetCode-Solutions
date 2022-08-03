class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.length();
        if(n==1) return s;
        if(n==2 && s[0]==s[1]) return "";
        for(int i=1;i<s.length();i++){
            if(i!=0 && s[i]==s[i-1]){
                s.erase(s.begin()+i-1);
                s.erase(s.begin()+i-1);
                i-=2;
            }
            // cout<<s<<" ";
        }
        return s;
    }
};