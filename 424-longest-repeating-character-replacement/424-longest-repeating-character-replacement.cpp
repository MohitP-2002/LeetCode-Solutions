class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> arr(26,0);
        int i=0,j=0,n=s.length();
        int ans=1;
        while(j<n){
            arr[s[j]-'A']++;
            int maxF=*max_element(arr.begin(),arr.end());
            if(j-i-maxF+1 > k){
                arr[s[i]-'A']--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};