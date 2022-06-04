class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int left[n], right[n];
        stack<int> s;
        int maxArea=0;
        //left limit calculate
        for(int i=0;i<n;i++){
            if(s.empty()){
                left[i]=0;
                s.push(i);
            }
            else {
                while(!s.empty() && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                left[i]=(s.empty())?0:s.top()+1;
                s.push(i);
            }
        }
        //right limit calculate
        while(!s.empty()){
            s.pop();
        }
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
                right[i]=n-1;
                s.push(i);
            }
            else {
                while(!s.empty() && heights[s.top()]>=heights[i]){
                    s.pop();
                }
                right[i]=(s.empty())?n-1:s.top()-1;
                s.push(i);
            }
            maxArea=max((right[i]-left[i]+1)*heights[i], maxArea);
        }
        return maxArea;
    }
};