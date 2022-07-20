class Solution {
public:
    string modifyString(string s) {
        if(s=="") return s;
        if(s.length()==1 && s[0]=='?') return "a";
        for(int i=0;i<s.length();i++){
            if(s[i]=='?'){
                for(char k ='a';k<='z';k++){
                    if(i==0){
                        if(k!=s[i+1]){
                            s[i]=k;
                            break;
                        }
                    }
                    else if(i==s.length()-1){
                        if(k!=s[i-1]){
                            s[i]=k;
                            break;
                        }
                    }
                    else{
                        if(k!=s[i+1] && k!=s[i-1]){
                            s[i]=k;
                            break;
                        }
                    }
                }
            }
        }
        return s;
    }
};