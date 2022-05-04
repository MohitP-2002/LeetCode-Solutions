class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans(temp.size(),0);
        stack<int> s;
        int n=temp.size()-1;
        for(int i=0;i<temp.size()-1;i++){
            s.push(temp[i]);
        }
        while(!s.empty()){
            if(temp[n]>s.top()){
                ans[n-1]=1;
            }
            else if(s.top()==temp[n]){
                if(ans[n]==0) ans[n-1]=0;
                else
                ans[n-1]=1+ans[n];
            }
            else{
                int c=0,f=0;
                for(int i=n;i<temp.size();i++){
                    if(temp[i]==s.top()){
                        if(ans[i]==0) c=0;
                        else
                        {c+=ans[i];
                        f=1;
                        c++;}
                        break;
                    }
                    else if(temp[i]>s.top()){
                        f=1;
                        c++;
                        break;
                    }
                    else c++;
                }
                if(f==1) ans[n-1]=c;
            }
            s.pop();
            n--;
        }
        return ans;
    }
};