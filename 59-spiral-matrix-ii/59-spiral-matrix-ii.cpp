class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n,vector<int>(n,1));
        int k=1,flag=1,left=0,right=n-1,top=0,bottom=n-1;
        while(left<=right && top<=bottom){
            //left to right
            if(flag==1){
                for(int i=left;i<=right;i++){
                    v[top][i]=k;
                    k++;
                }
                top++;
                flag=2;
            }
            //top to bottom
            else if(flag==2){
                for(int i=top;i<=bottom;i++){
                    v[i][right]=k;
                    k++;
                }
                right--;
                flag=3;
            }
            //right to left
            else if(flag==3){
                for(int i=right;i>=left;i--){
                    v[bottom][i]=k;
                    k++;
                }
                bottom--;
                flag=4;
            }
            //bottom to top
            else if(flag==4){
                for(int i=bottom;i>=top;i--){
                    v[i][left]=k;
                    k++;
                }
                left++;
                flag=1;
                
            }
        }
        return v;
    }
};