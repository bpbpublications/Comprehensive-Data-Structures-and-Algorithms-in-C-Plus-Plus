//Ex18.cpp : Write a program to rotate a matrix 90 degree in a clockwise direction.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row=3;
static const int col=3;

int main()
{
	int mat[row][col] = { {1,2,3}, {4,5,6}, {7,8,9} };

	cout << "The matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

	//Transpose the matrix
	int temp;
	for(int i=0; i<col; i++)
	{
		for(int j=0; j<i; j++)
		{
			temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}

	//Reverse the columns
	for(int i=0,k=col-1; i<k; i++,k--)
	{
		for(int j=0; j<row; j++)
		{
			temp = mat[j][i];
			mat[j][i] = mat[j][k];
			mat[j][k] = temp;
		}
	}

	cout << "After rotating the matrix 90 degree clockwise :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

	return 0;
}//End of main()
