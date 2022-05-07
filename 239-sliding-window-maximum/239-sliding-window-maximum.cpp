class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
         multiset<int,greater<int>> p;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
           p.insert(arr[i]);
           if(p.size()>k){
                p.erase(p.find(arr[i-k]));
            }
            if(p.size()==k){
                v.push_back(*p.begin());
            }
        }
        return v;    }
};