class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]=i;
        }
        int maxy=0, prev=-1;
        for(int i=0;i<s.length();i++){
            maxy=max(maxy,m[s[i]]);
            if(maxy==i){
                v.push_back(maxy-prev);
                prev=maxy;
            }
        }
        return v;
    }
};