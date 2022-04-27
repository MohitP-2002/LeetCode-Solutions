class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int i=0,j=0;
        while(i<m+n && j<n){
            if(a[i]>b[j]){
                for(int k=m+n-1;k>=i+1;k--){
                    a[k]=a[k-1];
                }
                a[i]=b[j];
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        for(int k=j;k<n;k++){
            a[m+k]=b[k];
        }
    }
};