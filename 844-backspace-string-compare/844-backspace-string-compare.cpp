class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=0,j=0,m=s.length(),n=t.length();
        string p="",q="";
        for(int i=0;i<m;i++){
            if(s[i]=='#'){
                p=p.substr(0,p.length()-1);
            }
            else{
                p+=s[i];
            }
        }
        for(int i=0;i<n;i++){
            if(t[i]=='#'){
                q=q.substr(0,q.length()-1);
            }
            else{
                q+=t[i];
            }
        }
        cout<<p<<" "<<q;
        if(p.compare(q)==0) return true;
        return false;
    }
};