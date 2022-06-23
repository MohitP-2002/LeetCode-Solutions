class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> m;
        unordered_set<int> set;
        for(auto i:s){
            m[i]++;
        }
        int ans=0;
        for(auto[k,v]:m){
            while(set.find(v)!=set.end()){
                v--;
                ans++;
            }
            if(v>0)
            set.insert(v);
        }
        return ans;
    }
};