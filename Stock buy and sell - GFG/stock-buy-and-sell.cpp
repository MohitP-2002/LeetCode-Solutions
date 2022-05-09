// { Driver Code Starts

// Program to find best buying and selling days
#include <bits/stdc++.h>

using namespace std;

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int *, int);

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, i;
        cin >> n;
        int price[n];
        for (i = 0; i < n; i++) cin >> price[i];
        // function call
        stockBuySell(price, n);
    }
    return 0;
}
// } Driver Code Ends


// User function template for C++

// This function finds the buy sell schedule for maximum profit
void stockBuySell(int price[], int n) {
    // code here
     vector<int>buy;
   vector<int>sell;
    
   if(n>=2 && price[0]<price[1])
   buy.push_back(0);
   for(int i=1;i<n;i++){
       if(price[i]<price[i-1] ){
            if((i-1)!=0){
               sell.push_back(i-1);
               
           }
           while(i!=n-1 && price[i+1]<price[i]){
               i++;
           }
           if(i!=n-1)
           buy.push_back(i);
          
       }
   }
   
   if(n>=2 && price[n-1]>price[n-2])
   sell.push_back(n-1);
   
   
   if(buy.size()==0 && sell.size()==0){
       cout<< "No Profit"<<endl;
   }
   else{
           
                for(int i=0;i<buy.size();i++){
           cout<< "("<<buy[i]<<" "<<sell[i]<<")"<<" ";
       }
           
          
      cout<<endl; 
       
       
   }
   
}