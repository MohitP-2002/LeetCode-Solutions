class Solution {
public:
    char nextGreatestLetter(vector<char>& a, char target) {
        set<char> s;
        for(auto i:a) s.insert(i);
        a.clear();
        for(auto i:s) a.push_back(i);
        int start=0,end=a.size()-1;
        int mn=INT_MAX;
        char ans=a[0];
        while(start<=end){
            int mid=start+(end-start)/2;
            if(a[mid]==target) {
                if(mid<a.size()-1)
                return a[mid+1];
                else{
                    return a[0];
                }
            }
            else if((int)target>(int)(a[mid])) start=mid+1;
            else{
                if(mn>(-(int)target+(int)(a[mid]))){
                    mn=-(int)target+(int)(a[mid]);
                    ans=a[mid];
                }
                end=mid-1;
            }
        }
        return ans;
    }
};