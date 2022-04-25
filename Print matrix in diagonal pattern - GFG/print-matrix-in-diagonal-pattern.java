// { Driver Code Starts
import java.util.*;
import java.lang.*;
import java.io.*;
class GFG
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            int n = Integer.parseInt(br.readLine().trim());
            int[][] mat = new int[n][n];
            String[] S = br.readLine().trim().split(" ");
            int i = 0;
            int j = 0;
            for(int k = 0; k < S.length; k++){
                mat[i][j] = Integer.parseInt(S[k]);
                j++;
                if(j == n){
                    i++;
                    j = 0;
                }
            }
            Solution obj = new Solution();
            int[] ans = obj.matrixDiagonally(mat);
            for(int it = 0; it < ans.length; it++){
                System.out.print(ans[it] + " ");
            }
            System.out.println();
        }
    }
}
// } Driver Code Ends


class Solution {
    public int[] matrixDiagonally(int[][] mat) {
        if(mat.length==0 || mat[0].length==0) return new int[0];
        int n=mat.length,m=mat[0].length;
        int i=0,j=0;
        int arr[]=new int[n*m];
        boolean up = true;
        int k=0;
        while(i<n && j<m){
            if(up){
                while(i>0 && j<m-1){
                    arr[k++]=mat[i][j];
                    i--;
                    j++;
                }
                arr[k++]=mat[i][j];
                if(j==m-1){
                    i++;
                }
                else j++;
                up=!up;
            }
            else{
                while(j>0&&i<n-1){
                    arr[k++]=mat[i][j];
                    i++;
                    j--;
                }
                arr[k++]=mat[i][j];
                if(i==n-1) j++;
                else i++;
                up=!up;
            }
        }
        return arr;
    }
}