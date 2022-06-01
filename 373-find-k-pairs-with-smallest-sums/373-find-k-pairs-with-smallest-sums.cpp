class Solution {
public:
    struct compare{
        bool operator()(pair<int,int>& p1, pair<int,int>& p2){
            return p1.first+p1.second < p2.first+p2.second;
        }
    };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> v;
        priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq;
        for(int i = 0; i < min((int)nums1.size(), k); i++){
            for(int j = 0; j < min((int)nums2.size(), k); j++){
                if(pq.size() < k)
                    pq.push(make_pair(nums1[i], nums2[j]));
                else if(nums1[i] + nums2[j] < pq.top().first + pq.top().second){
                    pq.push(make_pair(nums1[i], nums2[j]));
                    pq.pop();
                }
                else break;
            }
        }
        while(!pq.empty()){
            v.push_back({pq.top().first,pq.top().second});
            pq.pop();
        }
        return v;
    }
};