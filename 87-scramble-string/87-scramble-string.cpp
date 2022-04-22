class Solution {
public:
    unordered_map<string,bool> m;
    bool solver(string s1,string s2){
        
        if(s1.compare(s2) ==0) return true;
        if(s1.length()<=1) return false;
        bool flag=false;
        string temp=s1+' '+s2;
        if(m.find(temp)!=m.end()) return m[temp];
        int len=s1.length();
        for(int i=1;i<s1.length();i++){
            
        if( solver(s1.substr(0,i), s2.substr(0,i)) && solver(s1.substr(i), s2.substr(i)))
        {
            flag=true;
            break;
        }
            if( solver(s1.substr(0,i), s2.substr(len-i)) && solver(s1.substr(i), s2.substr(0,len-i)))
            {
                flag=true;
                break;
            }   
        }
        return m[temp]=flag;
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        if(s1.length()==0) return true;
        if(s1.length()==1 && s1.compare(s2)==0) return true;
        return solver(s1,s2);
    }
};