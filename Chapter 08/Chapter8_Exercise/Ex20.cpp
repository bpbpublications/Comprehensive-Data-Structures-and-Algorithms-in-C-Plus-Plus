// Ex20.cpp : Write a program to sort the elements of a matrix (i) Row-wise (ii) Column-wise.

#include<iostream>
#include<iomanip>
using namespace std;

static const int row = 4;
static const int col = 4;

void sortRowwise(int mat[row][col])
{
	int i,j,k,temp,xchanges;
	for(k=0; k<row; k++)
	{
		//Bubble sort
		for(i=0; i<col-1 ;i++)
		{
			xchanges = 0;
			for(j=0; j<col-1-i; j++)
			{
				if(mat[k][j] > mat[k][j+1])
				{
					temp=mat[k][j];
					mat[k][j]=mat[k][j+1];
					mat[k][j+1]=temp;
					xchanges++;
				}
			}
			if(xchanges==0) //If list is sorted
				break;
		}
	}
}//End of sortRowwise()

void sortColumnwise(int mat[row][col])
{
	int k,xchanges,i,j,temp;
	for(k=0; k<col; k++)
	{
		//Bubble sort
		for(i=0; i<row-1 ;i++)
		{
			xchanges=0;
			for(j=0; j<row-1-i; j++)
			{
				if(mat[j][k] > mat[j+1][k])
				{
					temp=mat[j][k];
					mat[j][k]=mat[j+1][k];
					mat[j+1][k]=temp;
					xchanges++;
				}
			}
			if(xchanges==0) //If list is sorted
				break;
		}
	}//End of for
}//End of sortColumnwise()

int main()
{
	int mat1[row][col] = { 
		{5,8,2,1}, 
		{3,6,9,4},
		{1,7,2,8},
		{8,3,5,7}
	};

	int mat2[row][col] = { 
		{5,8,2,1}, 
		{3,6,9,4},
		{1,7,2,8},
		{8,3,5,7}
	};

	cout << "The matrix 1 is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat1[i][j];
		cout << "\n";
	}
	cout << "\n";

	sortRowwise(mat1);

	cout << "After sorting row-wise, the matrix 1 is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat1[i][j];
		cout << "\n";
	}
	cout << "\n";


	cout << "The matrix 2 is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat2[i][j];
		cout << "\n";
	}
	cout << "\n";

	sortColumnwise(mat2);

	cout << "After sorting column-wise, the matrix 2 is :\n";
	for(int i=0; i<row; i++)
	{
		for(int j=0; j<col; j++)
			cout << setw(5) << mat2[i][j];
		cout << "\n";
	}
	cout << "\n";

}//End of main()

