//P9.cpp : Program for transpose of matrix.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row=3;
static const int col=4;

int main()
{
	int mat1[row][col] = { {3,2,1,5}, {6,5,8,2}, {9,3,4,1} };
	int mat2[col][row];

	cout << "The matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat1[i][j];
		cout << "\n";
	}
	cout << "\n";

	//Transpose
	for(int i=0; i<col; i++)
		for(int j=0; j<row; j++)
			mat2[i][j] = mat1[j][i];


	cout << "Transpose of matrix is :\n";
	for(int i=0; i<col; i++)
	{
		for(int j=0; j<row; j++)
			cout << setw(5) << mat2[i][j];
		cout << "\n";
	}
	cout << "\n";

	return 0;
}//End of main()

