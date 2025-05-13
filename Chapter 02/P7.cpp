//P7.cpp : Program for addition of two matrices.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row=3;
static const int col=4;

int main()
{
	int mat1[row][col] = { {1,2,8,4}, {5,6,7,8}, {3,2,1,4} };
	int mat2[row][col] = { {2,5,4,2}, {1,5,2,6}, {9,4,7,2} };
	int mat3[row][col];

	//Addition of matrices
	for(int i=0; i<row; i++)
		for(int j=0; j<col; j++)
			mat3[i][j] = mat1[i][j]+mat2[i][j];

	cout << "Matrix 1 :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat1[i][j];
		cout << "\n";
	}
	cout << "\n";

	cout << "Matrix 2 :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat2[i][j];
		cout << "\n";
	}
	cout << "\n";

	cout << "The resultant Matrix 3 :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat3[i][j];
		cout << "\n";
	}
	cout << "\n";

	return 0;
}//End of main()

