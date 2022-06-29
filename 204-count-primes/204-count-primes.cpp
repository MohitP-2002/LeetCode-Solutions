class Solution {
public:
    //sieve of erastothenes
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<bool>prime(n+1, true);
        for(int i=2;i<sqrt(n);i++){
            if(prime[i]){
                for(int j=i*i; j<n; j+=i){
                    prime[j]=false;
                }
            }
        }
        int count=0;
        for(int i=2;i<n;i++){
            if(prime[i]) count++;
        }
        return count;
    }
};