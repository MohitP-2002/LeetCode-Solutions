class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans=0;
        int i=0,j=height.size()-1;
        while(i<j){
            int res=(min(height[i],height[j]))*(j-i);
            ans=max(ans,res);
            if(height[i]>height[j]) j--;
            else i++;
        }
        return ans;
    }
};