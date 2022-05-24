class Solution {
public:
    int jump(vector<int>& A) {
        int jumps=0,cur=0,curF=0;
        for(int i=0;i<A.size()-1;i++)
        {
            curF=max(curF, i+A[i]);
            if(i==cur) {
                jumps++;
                cur=curF;
            }
        }
        return jumps;
    }
};