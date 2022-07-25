class Solution {
public:
    int helper(vector<string>& arr, string str, int i){
        unordered_set<char> set;
        for(auto i:str) set.insert(i);
        if(set.size()!=str.size()) return 0;
        int ans=str.length();
        for(int k=i;k<arr.size();k++){
            int temp=helper(arr,str+arr[k],k+1);
            ans=max(ans,temp);
        }
        return ans;
    }
    int maxLength(vector<string>& arr) {
        string str="";
        return helper(arr,str,0);
    }
};