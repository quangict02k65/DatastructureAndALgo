// A Backtracking program in
// C++ to solve Sudoku problem
#include <bits/stdc++.h>
using namespace std;


#define UNASSIGNED 0

#define N 9

//if all element 0 in the grid has assigned.
bool FindUnassignedLocation(int grid[N][N])
							//int& row, int& col)
{
	for (int row = 0; row < N; row++)
		for (int col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

//check whether element appeared in row or not ? 
bool UsedInRow(int grid[N][N], int row, int num)
{
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

//equivalent with useinrow.
bool UsedInCol(int grid[N][N], int col, int num)
{
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

//check in matrix 3x3.
bool UsedInBox(int grid[N][N], int boxStartRow,
			int boxStartCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + boxStartRow][col + boxStartCol] == num)
				return true;
	return false;
}

//check whether element can place in this cell or not ?
bool isSafe(int grid[N][N], int row,
			int col, int num)
{
	return !UsedInRow(grid, row, num)
		&& !UsedInCol(grid, col, num)
		&& !UsedInBox(grid, row - row % 3, col - col % 3, num)
		&& grid[row][col] == UNASSIGNED;
}

//print grid
void printGrid(int grid[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
			cout << grid[row][col] << " ";
		cout << endl;
	}
}

bool SolveSudoku(int grid[N][N])
{
	int row, col;
	//if grid has assigned complete , function is finished.
	if (!FindUnassignedLocation(grid))
		return true;

	for (int num = 1; num <= 9; num++)
	{
		
		// Check if looks promising
		if (isSafe(grid, row, col, num))
		{
			grid[row][col] = num;

			// Return, if success
			if (SolveSudoku(grid))
				return true;

			// Failure, unmake & try again
			grid[row][col] = UNASSIGNED;
		}
	}
	
	// This triggers backtracking
	return false;
}

int main()
{
	// 0 means unassigned cells
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

	// for(int i = 0; i < N; i ++){
	// 	for(int j = 0; j < N; j++){
	// 		cin>>grid[i][j];
	// 	}
	// }

	if (SolveSudoku(grid) == true)
		printGrid(grid);
	else
		cout << "No solution exists";
	//cout<<cnt<<endl;

	return 0;
}

// This is code is contributed by rathbhupendra
