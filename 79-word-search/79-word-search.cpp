class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, int n , int m, int index, string word){
        if(index==word.size()) return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[index]) return false;
        board[i][j]='#';
        bool ret = dfs(board, i+1, j, n, m, index+1, word) || dfs(board, i-1, j, n, m, index+1, word) || dfs(board, i, j-1, n, m, index+1, word) || dfs(board, i, j+1, n, m, index+1, word);
        board[i][j]=word[index];
        return ret;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int index=0;
        int n = board.size(), m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[index]){
                    if(dfs(board, i, j, n, m, index, word)) return true;
                }
            }
        }
        return false;
    }
};