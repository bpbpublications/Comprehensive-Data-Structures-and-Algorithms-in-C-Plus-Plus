//Ex10.cpp : Program to interchange first and last rows of a matrix.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row = 4;
static const int col = 4;

int main()
{
	int mat[row][col] = { 
		{1,2,3,4}, 
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	cout << "The matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

	int temp;
	//Interchange first and last row
	for(int i=0; i<col; i++)
	{
		temp = mat[0][i];
		mat[0][i] = mat[row-1][i];
		mat[row-1][i] = temp; 
	}

	cout << "After interchanging first and last row, the matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

}//End of main()