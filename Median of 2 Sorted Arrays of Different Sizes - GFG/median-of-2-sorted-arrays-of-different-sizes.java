// { Driver Code Starts
//Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class Driver
{
    public static void main(String args[]) 
	{ 
	    Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int []a = new int[n];
            for (int i = 0; i < n; i++) a[i] = sc.nextInt();
            
            int  m= sc.nextInt();
            int []b = new int[m];
            for (int i = 0; i < m; i++) b[i] = sc.nextInt();
            
            double res = new GFG().medianOfArrays(n, m, a, b);
            
            if (res == (int)res) System.out.println ((int)res);
            else System.out.println (res);
        }
    		
	} 
}// } Driver Code Ends


//User function Template for Java

class GFG 
{ 
    static double medianOfArrays(int n, int m, int a[], int b[]) 
    {
        // Your Code Here
        ArrayList<Double> arr = new ArrayList();
       for(double i : a){
           arr.add(i);
       }
       for(double i : b){
           arr.add(i);
       }
       Collections.sort(arr); 
       if((m+n)%2 != 0){
           return (arr.get((((m+n)+1)/2)-1));
       }
       double a1 = arr.get(((m+n)/2)-1);
       double a2 = arr.get(((m+n)+1)/2);
       //System.out.println((a1 + a2)/2);
       //System.out.println(a2);
       return (a1 + a2)/2;
    }
       
}