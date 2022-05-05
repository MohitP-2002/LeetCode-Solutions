class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1;
        if(x==1) return 1;
        if(n==-2147483648) {
            if(x==-1) return 1;
            return 0;
        }
        if(n<0) {
            n = -n;
            x = 1/x;
        }
        double ans = 1;
        while(n>0){
            if(n&1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};