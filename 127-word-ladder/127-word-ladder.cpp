class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_set<string> s;
        for(auto i:wordList) s.insert(i);
        if(s.find(endWord)==s.end()) return 0;
        int ans=0;
        q.push(beginWord);
        while(!q.empty()){
            int size=q.size();
            ans+=1;
            while(size--){
                string word=q.front();
                q.pop();
                for(int i=0;i<word.length();i++){
                string bk=word;
                for(char k='a' ; k<='z' ;k++){
                    bk[i]=k;
                    if(bk.compare(word)==0) continue;
                    if(bk.compare(endWord)==0) return ans+1;
                    if(s.find(bk)!=s.end()){
                        q.push(bk);
                        s.erase(bk);
                    }
                }
            }
            }
        }
        return 0;
    }
};