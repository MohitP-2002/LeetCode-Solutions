class Solution {
public:
    struct comp{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return (a.first==b.first)?a.second<b.second:a.first<b.first;
        }
    };
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>  v;
        priority_queue<pair<int,int>, vector<pair<int,int>>, comp> q;
        for(auto i:arr){
            q.push({abs(i-x), i});
            if(q.size()>k) q.pop();
        }
        while(!q.empty()){
            v.push_back(q.top().second);
            q.pop();
        }
        sort(v.begin(), v.end());
        return v;
    }
};