//Ex16.cpp : Program to print a rectangular matrix spirally.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row = 5;
static const int col = 6;

int main()
{
	int mat[row][col] =
	{
		{95,67,32,35,44,65},
		{12,11,16,93,29,59},
		{82,13,21,31,27,17},
		{24,18,28,15,33,20},
		{39,30,26,23,34,37}
	};

	cout << "The square matrix is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(4) << mat[i][j];
		cout << "\n";
	}

	cout << "\nPrinting the rectangular matrix spirally :\n";

	int k;
	for(int rStart=0,cStart=0,rEnd=row-1,cEnd=col-1; rStart<=rEnd && cStart<=cEnd; rStart++,cStart++,rEnd--,cEnd--)
	{
      	for(k=cStart; k<=cEnd; k++) 
			cout << mat[rStart][k] << " ";
		for(k=rStart+1; k<=rEnd; k++) 
			cout << mat[k][cEnd] << " ";
		if(rStart<rEnd)
			for(k=cEnd-1; k>=cStart; k--)
				cout << mat[rEnd][k] << " ";
		if(cStart<cEnd)
			for(k=rEnd-1; k>=rStart+1; k--)
				cout << mat[k][cStart] << " ";
	}

	cout << "\n";

	return 0;
}//End of main()
