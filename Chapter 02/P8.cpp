//P8.cpp : Program for multiplication of two matrices.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row1=3;
static const int col1=4;
static const int row2=col1;
static const int col2=2;

int main()
{
	int mat1[row1][col1] = { {2,1,4,3}, {5,2,7,1}, {3,1,4,2} };
	int mat2[row2][col2] = { {1,2}, {3,4}, {2,5}, {6,2} };
	int mat3[row1][col2];

	//Multiplication of matrices
	for(int i=0; i<row1; i++)
		for(int j=0; j<col2; j++)
		{
			mat3[i][j] = 0;
			for(int k=0; k<col1; k++)
				mat3[i][j] += mat1[i][k]*mat2[k][j];
		}

	cout << "Matrix 1 :\n";
	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<col1; j++)
			cout << setw(5) << mat1[i][j];
		cout << "\n";
	}
	cout << "\n";

	cout << "Matrix 2 :\n";
	for(int i=0; i<row2; i++)
	{
		for(int j=0; j<col2; j++)
			cout << setw(5) << mat2[i][j];
		cout << "\n";
	}
	cout << "\n";

	cout << "The resultant Matrix 3 :\n";
	for(int i=0; i<row1; i++)
	{
		for(int j=0; j<col2; j++)
			cout << setw(5) << mat3[i][j];
		cout << "\n";
	}
	cout << "\n";

	return 0;
}//End of main()

