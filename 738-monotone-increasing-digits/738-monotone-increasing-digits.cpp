class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int pointer=s.size();
        for(int i=s.size()-1;i>0;i--){
            if(s[i] < s[i-1]){
                s[i-1]=s[i-1]-1;
                pointer=i;
            }
        }
        for(int i=pointer;i<s.size();i++){
            s[i]='9';
        }
        return stoi(s);
    }
};