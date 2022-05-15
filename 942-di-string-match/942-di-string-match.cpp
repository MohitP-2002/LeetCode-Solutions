class Solution {
public:
    vector<int> diStringMatch(string A) {
        vector<int> v;
        int B = A.length()+1;
    int great=B-1,small=0;
    for(int i=0;i<A.length();i++){
        if(A[i]=='I'){
             v.push_back(small);
             small++;
        }
        else{
            v.push_back(great);
            great--;
        }
    }
    if(great>0) v.push_back(great);
    else v.push_back(small);
    return v;
    }
};