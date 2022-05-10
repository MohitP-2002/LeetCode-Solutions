// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inv_count=0;
     void merge(long long arr[], long long start, long long mid,  long long end){
          long long n1 = mid - start + 1;    
          long long n2 = end - mid;    
     
            long long LeftArray[n1], RightArray[n2]; //temporary arrays  
     
           /* copy data to temp arrays */  
           for (long long i = 0; i < n1; i++)    
               LeftArray[i] = arr[start + i];    
           
           for (long long j = 0; j < n2; j++)    
           RightArray[j] = arr[mid + 1 + j];    
           
           long long i = 0; /* initial index of first sub-array */  
           long long j = 0; /* initial index of second sub-array */   
           long long k = start;  /* initial index of merged sub-array */  
           
           while(i<n1 and j<n2){
               
               if(LeftArray[i] <= RightArray[j]){
                   arr[k] = LeftArray[i];
                   i++;
               }else{
                   arr[k] = RightArray[j];
                   j++;
                   
                   // this step :)
                   inv_count += n1-i;
               }
               
               k++;
           }
           
           
           while(i<n1){
               arr[k] = LeftArray[i];    
                i++;    
                k++;    
           }
           while(j<n2){
               arr[k] = RightArray[j];    
                j++;    
                k++;   
                
           }
           
           return ;
   }

    void merge_sort(long long arr[], long long start, long long end){
       
       if(start >= end)
           return ;
       
       long long mid = start + (end - start)/2;
       merge_sort(arr, start, mid);
       merge_sort(arr,mid+1,end);
       merge(arr, start,mid,end);
       
   }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
       merge_sort(arr, 0,N-1);
      
      return inv_count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends