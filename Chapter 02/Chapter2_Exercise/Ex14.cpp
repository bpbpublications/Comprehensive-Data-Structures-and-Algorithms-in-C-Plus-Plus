// Ex14.cpp : Program to find out whether a square matrix is symmetric or not.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row = 3;
static const int col = row;

bool isSymmetric(int mat[row][col], int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(mat[i][j] != mat[j][i])
				return false;
		}
	}

	return true;
}//End of isSymmetric()

int main()
{
	int mat[row][col] = { {1,8,5}, {8,3,9}, {5,9,4} };

	cout << "The matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

	if(isSymmetric(mat,row))
		printf("Matrix is symmetric\n");
	else
		printf("Matrix is not symmetric\n");	

	return 0;
}//End of main()


