//Ex11.cpp : Program to reverse the rows of a matrix.

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
	for(int i=0,k=row-1; i<k; i++,k--)
	{
		for(int j=0; j<col; j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[k][j];
			mat[k][j] = temp; 
		}
	}

	cout << "After reversing rows, the matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

}//End of main()