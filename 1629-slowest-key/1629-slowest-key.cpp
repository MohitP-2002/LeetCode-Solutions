class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        vector<int> v(26,0);
        v[keysPressed[0]-'a']=releaseTimes[0];
        for(int i=1;i<keysPressed.size();i++){
             v[keysPressed[i]-'a']=max(v[keysPressed[i]-'a'] ,releaseTimes[i]-releaseTimes[i-1]);
        }
        char res;int len=0;
        for(int i=0;i<26;i++){
            cout<<v[i]<<" ";
            if(v[i]>=len){
                len=v[i];
                res=i+'a';
            }
        }
        return res;
    }
};