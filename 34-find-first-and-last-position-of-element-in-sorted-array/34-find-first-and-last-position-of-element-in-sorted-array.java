class Solution {
    public int[] searchRange(int[] nums, int target) {
        int n=nums.length;
        int i=0,j=n-1;
        int a[]={-1,-1};
        if(n==1)
        {
            if(nums[0]==target)
            {
                a[0]=0;
                a[1]=0;
                return a;
            }
            else
                return a;
        }
        while(i<=j)
        {
            if(nums[i]==target)
            {
                a[0]=i;
                for(int k=i;k<n;k++)
                {
                    if(nums[k]==target)
                    {
                        a[1]=k;
                    }
                    else
                        break;
                }
                break;
            }
            if(nums[j]==target)
            {
                a[1]=j;
                for(int k=j;k>=0;k--)
                {
                    if(nums[k]==target)
                    {
                        a[0]=k;
                    }
                    else
                        break;
                }
                break;
            }
            if(nums[i]>target)
                break;
            if(nums[i]<target)
                i++;
            if(nums[j]<target)
                break;
            if(nums[j]>target)
                j--;
        }
        return a;
    }
}