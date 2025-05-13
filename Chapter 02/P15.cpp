//P15.cpp : Program to print a square matrix spirally.

#include<iostream>
#include<iomanip>
using namespace std;

static const int maxSize = 10;

int main()
{
	int arr[maxSize][maxSize] =
	{
		{95,67,32,35,44,65},
		{12,11,16,93,29,59},
		{82,13,21,31,27,17},
		{24,18,28,15,33,20},
		{39,30,26,23,34,37},
		{19,38,52,14,36,22}
	};

	int n = 6;
	int i,j,start,end;

	cout << "The square matrix is :\n";
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			cout << setw(4) << arr[i][j];
		cout << "\n";
	}

	cout << "\nPrinting the square matrix spirally :\n";

	for(start=0,end=n-1; start<=end; start++,end--)
	{
		for(i=start; i<=end; i++)
			cout << arr[start][i] << " ";
		for(i=start+1; i<=end; i++)
			cout << arr[i][end] << " ";
		for(i=end-1; i>=start; i--)
			cout << arr[end][i] << " ";
		for(i=end-1; i>=start+1; i--)
			cout << arr[i][start] << " ";
	}

	cout << "\n";

	return 0;
}//End of main()

