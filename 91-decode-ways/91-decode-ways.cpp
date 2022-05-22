class Solution {
public:
    int solver(int i, string& s, int mem[]){
        if(mem[i]!=-1) return mem[i];
        if(i==s.length()) return mem[i]=1;
        if(s[i]=='0') return mem[i]=0;
        int res=solver(i+1, s, mem);
        if((i<s.length()-1) && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7'))){
           res+=solver(i+2,s,mem);
        }
        return mem[i]=res;
    }
    int numDecodings(string s) {
        int mem[s.length()+1];
        memset(mem,-1,sizeof(mem));
        mem[s.length()]=1;
        return s.empty()?0:solver(0,s,mem);
    }
};