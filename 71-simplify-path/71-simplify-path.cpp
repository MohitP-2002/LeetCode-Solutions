class Solution {
public:
    string simplifyPath(string path) {
        stack<string> s;
        string res="";
        for(int i=0;i<path.length();i++){
            if(path[i]!='/'){
                res+=path[i];
            }
            else{
                if(res=="" || res==".") {
                    res="";
                    continue;
                }
                if(res==".."){
                    if(!s.empty())
                    s.pop();
                    res="";
                    continue;
                }
                s.push(res);
                res="";
            }
        }
        if(res!=""){
            if(res=="..") {
                if(!s.empty()) s.pop();
            }
            else if(res==".");
            else {
                s.push(res);
            }
        }
        res="";
        vector<string> v;
        while(!s.empty()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        for(auto i:v){
            res+="/" + i;
        }
        if(res=="") return "/";
        return res;
    }
};