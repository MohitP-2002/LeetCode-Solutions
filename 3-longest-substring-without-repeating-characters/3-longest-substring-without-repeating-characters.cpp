class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        map<char,int>m;
        int n = s.length();
        for(int i=0;i<n;i++){
            int j=i;
            m.clear();
            while(j<n){
                if(m.find(s[j])==m.end()){
                    m[s[j]]++;
                    j++;
                }
                else{
                    break;
                }
            }
            ans=max(ans,j-i);
        }
        return ans;
    }
};