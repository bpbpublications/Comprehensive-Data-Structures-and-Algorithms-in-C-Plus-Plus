//Ex17.cpp : program to print Spiral Matrix.

#include<iostream>
#include<iomanip>
using namespace std;

static const int maxSize = 10;

int main()
{
	int mat[maxSize][maxSize];
	int n = 5;
	int i,j,start,end;

	int num = 1;
	for(start=0,end=n-1; start<=end; start++,end--)
	{
		for(i=start; i<=end; i++)
			mat[start][i] = num++;
		for(i=start+1; i<=end; i++)
			mat[i][end] = num++;
		for(i=end-1; i>=start; i--)
			mat[end][i] = num++;
		for(i=end-1; i>=start+1; i--)
			mat[i][start] = num++;
	}

	cout << "The spiral matrix for " << n << " is:\n";
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			cout << setw(4) << mat[i][j];
		cout << "\n";
	}
	cout << "\n";

	return 0;
}//End of main()
