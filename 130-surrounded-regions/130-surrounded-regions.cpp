class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!='O') return;
        board[i][j]='$';
        dfs(board,i+1,j,n,m);
        dfs(board,i-1,j,n,m);
        dfs(board,i,j-1,n,m);
        dfs(board,i,j+1,n,m);
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(), m=board[0].size();
        if(n==0) return;
        for(int i=0;i<board.size();i++){
            if(board[i][0]=='O')
            dfs(board,i,0,board.size(), board[0].size());
            if(board[i][m-1]=='O')
            dfs(board,i,m-1,board.size(), board[0].size());
        }
        for(int j=0;j<board[0].size();j++){
            if(board[0][j]=='O')
            dfs(board,0,j,board.size(), board[0].size());
            if(board[n-1][j]=='O')
            dfs(board,n-1,j,board.size(), board[0].size());
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='$') board[i][j]='O';
            }
        }
    }
};