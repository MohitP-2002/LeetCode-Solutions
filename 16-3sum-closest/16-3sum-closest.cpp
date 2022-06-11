class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
           int n=arr.size();
            int ans=arr[0]+arr[1]+arr[2];
            sort(arr.begin(),arr.end());
            for(int k=0;k<n;k++){
                int i=k+1,j=n-1;
                while(i<j){
                    int sum = arr[i]+arr[j]+arr[k];
                    if(i==k){ i++;
                            continue;}
                    if(j==k) {j--;
                             continue;}
                    if(sum==target && j!=k && i!=k){
                        return target;
                    }
                    if(abs(target-sum)<abs(target-ans)) {
                        ans = sum;
                    }
                    else if(sum>target){
                        j--;
                    }
                    else {
                        i++;
                    }
                }
            }
        return ans;
    }
};