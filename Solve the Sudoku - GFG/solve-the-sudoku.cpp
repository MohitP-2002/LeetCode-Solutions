// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find a solved Sudoku. 
    bool check(int board[N][N], int i, int j, int val)
    {
        int row = i - i%3, column = j - j%3;
        for(int x=0; x<9; x++) if(board[x][j] == val) return false;
        for(int y=0; y<9; y++) if(board[i][y] == val) return false;
        for(int x=0; x<3; x++)
        for(int y=0; y<3; y++)
            if(board[row+x][column+y] == val) return false;
        return true;
    }
    bool solveSudoku(int board[N][N], int i, int j)
    {
        if(i==9) return true;
        if(j==9) return solveSudoku(board, i+1, 0);
        if(board[i][j] != 0) return solveSudoku(board, i, j+1);

        for(int c=1;c<=9;c++)
        {
            if(check(board, i, j, c))
            {
                board[i][j] = c;
                if(solveSudoku(board, i, j+1)) return true;
                board[i][j] =0;
            }
        }

        return false;
    }
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        solveSudoku(grid,0,0);
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends