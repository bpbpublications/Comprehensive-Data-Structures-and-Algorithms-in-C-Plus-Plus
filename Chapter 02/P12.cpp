//P12.cpp : Program for Pascal's triangle.

#include<iostream>
#include<iomanip>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize][maxSize];
	int n = 7; //Number of lines for triangle
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
		{
			if(j==0 || i==j)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
		}
	}

	cout << "Pascal triangle :\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=i; j++)
			cout << setw(5) << arr[i][j];
		cout << "\n";
	}

	return 0;
}//End of main()

