class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> s;
        for(auto j:emails){
            for(int i=0;i<j.length();i++){
                if(j[i]=='.'){
                    j=j.substr(0,i)+j.substr(i+1,j.length()-i);
                }
                if(j[i]=='+'){
                    int flag=0;
                    for(int k=i;k<j.length();k++)
                    {
                        if(j[k]=='@'){
                            flag=k;
                            break;
                        }
                    }
                    j=j.substr(0,i)+j.substr(flag,j.length()-flag+1);
                    // cout<<j<<", ";
                    break;
                }
                if(j[i]=='@') break;
            }
            s.insert(j);
        }
        return s.size();
    }
};