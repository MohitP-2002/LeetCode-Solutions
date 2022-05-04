class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int>  ans;
        stack<int> s;
        for(int i=0;i<a.size();i++){
            if(a[i]>0){
                s.push(a[i]);
            }
            else{
                int c=0;
                while(!s.empty() && (s.top()*a[i])<0 ){
                    if(abs(s.top())==abs(a[i])) {
                        s.pop();
                        c=1;
                        break;
                    }
                    else if(s.top()<abs(a[i])){
                        s.pop();
                    }
                    else {
                        c=1;
                        break;
                    }
                }
                if(c==0){
                    s.push(a[i]);
                }
                               
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};