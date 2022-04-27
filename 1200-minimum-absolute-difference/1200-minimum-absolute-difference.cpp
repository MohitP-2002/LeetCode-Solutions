class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> v;
        int n=arr.size();
        int mn=INT_MAX;
        for(int i=1;i<n;i++){
            mn=min(mn,arr[i]-arr[i-1]);
        }
        vector<int> s;
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==mn){
                s.push_back(arr[i-1]);
                s.push_back(arr[i]);
                v.push_back(s);
            }
            s.clear();
        }
        return v;
    }
};