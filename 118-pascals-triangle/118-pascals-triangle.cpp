class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>  v(numRows, vector<int>(numRows,1));
         vector<int> s;
        for(int i=2;i<numRows;i++){
            for(int k=1;k<i;k++){
                v[i][k]=(v[i-1][k-1]+v[i-1][k]);
            }
        }
        vector<vector<int>>  ans;
        for(int i=0;i<numRows;i++){
            s.clear();
            for(int j=0;j<=i;j++){
                s.push_back(v[i][j]);
            }
            ans.push_back(s);
        }
        return ans;
    }
};