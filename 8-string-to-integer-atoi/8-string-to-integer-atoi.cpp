class Solution {
public:
    int myAtoi(string s) {
        int len = s.size();
        if (len == 0) return 0;
        
        int i = 0;
        while (i < len && s[i] == ' ') i ++;
        
        bool neg = false;
        if (s[i] == '+') {
            neg = false; 
            i ++;
        } else if (s[i] == '-') {
            neg = true;
            i ++;
        }
        
        long long ans = 0;
        while (i < len) {
            if (s[i] >= '0' && s[i] <= '9') {
                ans = ans * 10 + s[i] - '0';
            } else {
                break;
            }
            
            if (ans > INT_MAX)
                break;
            i ++;
        }
        
        if (neg)
            ans = - ans;
        if (ans > INT_MAX)
            ans = INT_MAX;
        if (ans < INT_MIN)
            ans = INT_MIN;
        return ans;
    }
};