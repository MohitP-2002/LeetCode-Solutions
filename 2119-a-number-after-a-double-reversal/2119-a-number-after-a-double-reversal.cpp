class Solution {
public:
    bool isSameAfterReversals(int num) {
        int rev=0,n=num;
        while(n>0){
            int d=n%10;
            rev=rev*10+d;
            n/=10;
        }
        n=rev;
        int rev2=0;
        while(n>0){
            int d=n%10;
            rev2=rev2*10+d;
            n/=10;
        }
        return rev2==num;
    }
};