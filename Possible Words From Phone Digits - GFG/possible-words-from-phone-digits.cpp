// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int n)
    {
        //Your code here
        string digits="";
        for(int i=0;i<n;i++){
            digits+=to_string(a[i]);
        }
        vector<string>v;
        if(n==0) return v;
        v.push_back("");
        vector<string> letters(10,"");
        letters[2]="abc";letters[3]="def";letters[4]="ghi";letters[5]="jkl";
        letters[6]="mno";letters[7]="pqrs";letters[8]="tuv";letters[9]="wxyz";
        for(auto i:digits){
            vector<string> tmp;
            for(auto x:letters[i -'0']){
                for(auto s:v){
                    tmp.push_back(s+x);
                }
            }
            v.swap(tmp);
        }
        sort(v.begin(),v.end());
        return v;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends