class Solution {
public:
    int maxProduct(vector<int>& A) {
        int p=1,q=1;
    int ans=INT_MIN;
    bool f=true;
    for(int i=0;i<A.size();i++){
        p*=A[i];
        q*=A[i];
        ans=max(ans,max(p,q));
        if(A[i]==0){
            p=1;q=1;
            f=true;
        }
        if(A[i]<0 && f==true){
            p=1;
            f=false;
        }
    }
    return ans;
    }
};