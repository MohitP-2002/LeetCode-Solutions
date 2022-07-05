class Solution {
public:
    struct Node{
        string word;
        int freq;
        int index;
    };
    struct comp{
        bool operator()(Node a, Node b){
          return a.freq > b.freq || (a.freq == b.freq && a.word < b.word);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> v;
        unordered_map<string, int> m;
        for(auto i:words) m[i]++;
        priority_queue<Node, vector<Node>, comp> q;
        for(auto i:m){
            q.push({i.first,i.second});
            if(q.size()>k){
                q.pop();
            }
        }
        while(!q.empty()){
            v.push_back(q.top().word);
            q.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};