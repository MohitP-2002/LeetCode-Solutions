class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pdt=1,c=0;
        vector<int> v;
        for(int k=0;k<nums.size();k++){
            pdt=pdt*nums[k];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                v.push_back(pdt/nums[i]);
            }
            else{
                if(c==1) v.push_back(0);
                else{
                    int p=1;
                    for(int k=0;k<nums.size();k++){
                        if(k==i) continue;
                        p*=nums[k];
                    }
                    v.push_back(p);
                    c++;   
                }
                 
            }
        }
        return v;
    }
};