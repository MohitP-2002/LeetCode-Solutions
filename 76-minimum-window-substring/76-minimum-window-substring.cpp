class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<int>map(128,0);
        for(auto i:t){
            map[i]++;
        }
        int counter=t.length();
        int start=0, end=0, minLen=INT_MAX, minStart=0;
        while(end<m){
            if(map[s[end]]>0) counter--;
            map[s[end]]--;
            end++;
            while(counter==0){
                if(end-start<minLen){
                    minLen=end-start;
                    minStart=start;
                }
                map[s[start]]++;
                if(map[s[start]]>0) counter++;
                start++;
            }
        }
        if(minLen==INT_MAX) return "";
        return s.substr(minStart, minLen);
    }
};