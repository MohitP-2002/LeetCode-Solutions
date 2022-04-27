class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        if(n==1) return 0;
        string s="";
        while(n>0){
            int d=n%2;
            n=n/2;
            s+=(d^1);
        }
        n=0;
        for(int i=0;i<s.length();i++){
            n+=(s[i]*pow(2,i));
        }
        return n;
    }
};