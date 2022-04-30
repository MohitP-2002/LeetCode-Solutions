class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        vector<int>  v;
        int n=matrix[0].size();
        int left=0,right=n-1, top=0, bottom=m-1;
        int flag=1;
        while(left<=right && top<=bottom){
            if(flag==1){
                for(int i=left;i<=right;i++){
                    v.push_back(matrix[top][i]);
                }
                ++top;
                flag=2;
            }
            else if(flag==2){
                for(int i=top;i<=bottom;i++){
                    v.push_back(matrix[i][right]);
                }
                --right;
                flag=3;
            }
            else if(flag==3){
                for(int i=right;i>=left;i--){
                    v.push_back(matrix[bottom][i]);
                }
                --bottom;
                flag=4;
            }
            else if(flag==4){
                for(int i=bottom;i>=top;i--){
                    v.push_back(matrix[i][left]);
                }
                ++left;
                flag=1;
            }
        }
        return v;
    }
};