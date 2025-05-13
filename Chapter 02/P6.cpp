//P6.cpp : Program to display the matrix.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row=3;
static const int col=4;

int main()
{
	int mat[row][col] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };

	cout << "The matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

	return 0;
}//End of main()

