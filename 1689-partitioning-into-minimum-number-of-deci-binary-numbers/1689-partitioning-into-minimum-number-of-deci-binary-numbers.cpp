class Solution {
public:
    int minPartitions(string s) {
        int max=0;
        for(int i=0;i<s.length();i++){
            if(max<s[i]-'0') max=s[i]-'0';
        }
        return max;
    }
};