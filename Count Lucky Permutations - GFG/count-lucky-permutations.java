//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read =
            new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S[] = read.readLine().split(" ");
            int N = Integer.parseInt(S[0]);
            int M = Integer.parseInt(S[1]);

            int arr[] = new int[(int)(N)];
int i=0;
            String inputLine2[] = read.readLine().trim().split(" ");
            for (i = 0; i < N; i++) {
                arr[i] = Integer.parseInt(inputLine2[i]);
            }
            int graph[][] = new int[M][2];
            for (i = 0; i < M; i++) {
                String S1[] = read.readLine().trim().split(" ");
                graph[i][0] = Integer.parseInt(S1[0]);
                graph[i][1] = Integer.parseInt(S1[1]);
            }

            Solution ob = new Solution();
            System.out.println(ob.luckyPermutations(N, M, arr, graph));
        }
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    long luckyPermutations(int N, int M, int arr[], int[][] graph) {
        // Code here
        int[][] adj = new int[N + 1][N + 1];
        
        for(int[] e : graph){
            adj[e[0]][e[1]]++;
            adj[e[1]][e[0]]++;
        }
        
        long[][] dp = new long[N][(1 << N)];
        
        for(int i=0; i<N; i++){
            dp[i][(1 << i)]++;
        }
        
        for(int i=1; i < (1 << N); i++){
            for(int j=0; j<N; j++){
                
                if(((i >> j) & 1) != 0 ){
                    
                    for(int k=0; k<N; k++){
                        
                        if(k != j && arr[k] != arr[j] && ((i >> k) & 1) != 0 && adj[arr[j]][arr[k]] == 1){
                            dp[j][i] += dp[k][(i ^ (1 << j))];
                        }
                        
                    }
                    
                }
                
            }
        }
        
        long counter = 0l;
        
        for(int i=0; i<N; i++){
            counter += dp[i][(1 << N) - 1];
        }
        
        return counter;
    }
}
