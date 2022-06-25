// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Code here
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

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends