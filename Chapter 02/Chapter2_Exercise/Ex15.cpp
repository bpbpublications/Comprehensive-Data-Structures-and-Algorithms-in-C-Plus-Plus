//Ex15.cpp : Program to find the sum of rows and columns of a 2-d array and store the sums in the same array.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row = 4;
static const int col = 5;

int main()
{
	int mat[row+1][col+1] = { 
		{1,2,2,1,4},
		{5,4,3,2,5},
		{6,3,2,1,4},
		{3,5,4,2,3}
	};

	cout << "The matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

	for(int i=0; i<row; i++)
	{
		mat[i][col] = 0;
		for(int j=0; j<col; j++)
			mat[i][col] += mat[i][j];
	}

	for(int i=0; i<col+1; i++)
	{
		mat[row][i] = 0;
		for(int j=0; j<row; j++)
			mat[row][i] += mat[j][i];
	}

	cout << "After sum of rows and columns, the matrix is :\n";
	for(int i=0; i<row+1; i++)
	{
		for(int j=0; j<col+1; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

}//End of main()

