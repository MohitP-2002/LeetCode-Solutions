class Solution {
public: 
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> count(26,0);
        for(auto i:s){
            count[i-'a']++;
        }
        int max=0,letter=0;
        for(int i=0;i<26;i++){
            if(max < count[i]){
                max=count[i];
                letter=i;
            }
        }
        if(max > (s.length()+1)/2) return  "";
        char res[n];
        int index=0;
        while(count[letter] > 0){
            res[index]=char(letter+'a');
            count[letter]--;
            index+=2;
        }
        for(int i=0;i<26;i++){
            while(count[i]>0){
                if(index>=n) index=1;
                res[index]=char(i+'a');
                count[i]--;
                index+=2;
            }
        }
        s="";
        for(int  i=0;i<n;i++) s+=res[i];
        return s;
    }
};