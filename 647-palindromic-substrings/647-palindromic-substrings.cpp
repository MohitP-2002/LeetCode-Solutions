class Solution {
public:
    int count=0;
    void solver(int i, int j , string s){
        while(i>=0 && j<s.length() && s[i]==s[j]){
            count++;
            i--;
            j++;
        }
    }
    int countSubstrings(string s) {
        if(s.length()==0) return 0;
        for(int i=0;i<s.length();i++){
            solver(i,i,s);
            solver(i,i+1,s);
        }
        return count;
    }
};