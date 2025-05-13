//Ex9.cpp : Program to find an element in a matrix, where the matrix is sorted row-wise and column-wise.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row = 3;
static const int col = 3;

int main()
{
	int mat[row][col] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int searchItem = 8;

	cout << "The matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

	int i, j;
	i=0, j=col-1;
	while(i<=col-1 && j>=0)
	{
		if(mat[i][j] == searchItem)	
		{
			cout << searchItem << " found at row : " << i << ", column : " << j << "\n";
			break;
		}
        if( mat[i][j] < searchItem )
			i++;
		else
			j--;
	}//End of while

	return 0;
}//End of main()

