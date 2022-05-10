class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>  v(n,-1);
        stack<int> s;
        for(int i=0;i<2*n;i++){
            while(!s.empty() && arr[s.top()]<arr[i%n]){
                auto x = s.top();
                s.pop();
                v[x%n]=arr[i%n];
            }
            s.push(i%n);
        }
        return v;
    }
};