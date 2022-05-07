class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
            set<vector<int>> v;
           int n=arr.size();
            vector<vector<int>>ans;
            vector<int>kk ;
            sort(arr.begin(),arr.end());
            for(int k=0;k<n;k++){
                int i=k+1,j=n-1;
                while(i<j){
                    if(i==k){ i++;
                            continue;}
                    if(j==k) {j--;
                             continue;}
                    if(arr[i]+arr[j]+arr[k]==0 && j!=k && i!=k){

                        kk.push_back(arr[i]);
                        kk.push_back(arr[j]);
                        kk.push_back(arr[k]);
                        sort(kk.begin(),kk.end());
                        v.insert(kk);
                        kk.clear();
                        i++;
                        j--;
                    }
                    else if(arr[i]+arr[j]+arr[k]>0)j--;
                    else i++;
                }
            }
        for(auto i:v) ans.push_back(i);
        return ans;
    }
};