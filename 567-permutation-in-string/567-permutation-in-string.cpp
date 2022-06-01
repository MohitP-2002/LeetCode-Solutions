class Solution {
public:
    bool isZero(int count[]){
        for(int i=0;i<26;i++){
            if(count[i]!=0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int l1=s1.length();
        int l2=s2.length();
        if(l2<l1) return false;
        int count[26]={0};
        for(int i=0;i<l1;i++){
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        if(isZero(count)) return true;
        for(int i=l1;i<l2;i++){
            count[s2[i]-'a']--;
            count[s2[i-l1]-'a']++;
            if(isZero(count)) return true;
        }
        return false;
    }
};