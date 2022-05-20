class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n =digits.length();
        vector<string>v;
        if(n==0) return v;
        v.push_back("");
        vector<string> letters(10,"");
        letters[2]="abc";letters[3]="def";letters[4]="ghi";letters[5]="jkl";
        letters[6]="mno";letters[7]="pqrs";letters[8]="tuv";letters[9]="wxyz";
        for(auto i:digits){
            vector<string> tmp;
            for(auto x:letters[i -'0']){
                for(auto s:v){
                    tmp.push_back(s+x);
                }
            }
            v.swap(tmp);
        }
        return v;
    }
};