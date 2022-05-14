// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GfG
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-->0)
        {
            int N = sc.nextInt();
            Solution ob = new Solution();
            ArrayList<Integer> ans = ob.factorial(N);
            for (Integer val: ans) 
                System.out.print(val); 
            System.out.println();
        }   
    }
}// } Driver Code Ends


//User function Template for Java

class Solution {
    static  void multiply(int x, ArrayList<Integer> a){
        int carry=0;
        for(int i=0;i<a.size();i++){
            int calc=a.get(i)*x+carry;
            a.set(i,calc%10);
            carry=calc/10;
        }
        while(carry>0){
            a.add(carry%10);
            carry=carry/10;
        }
    }
    static ArrayList<Integer> factorial(int N){
        //code <
        ArrayList<Integer> a=new ArrayList<>();
        a.add(1);
        for(int i=2;i<=N;i++){
            multiply(i,a);
        }
        Collections.reverse(a);
        return a;
    }
}