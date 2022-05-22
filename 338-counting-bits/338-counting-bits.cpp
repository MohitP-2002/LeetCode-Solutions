class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;
        if(n==0){
            v.push_back(0);
                return v;
        }
        v.push_back(0);
        v.push_back(1);
        for(int i=2;i<=n;i++){
            v.push_back(__builtin_popcount(i));
        }
        return v;
    }
};