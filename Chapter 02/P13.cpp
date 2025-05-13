//P13.cpp : Program for magic matrix.

#include<iostream>
#include<iomanip>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize][maxSize];
	int n = 3;

	int i = n-1;
	int j = (n-1)/2;
	int num;

	for(num=1; num <= n*n; num++)
	{
		arr[i][j] = num;
		i++; //move down
		j--; //move left

		if(num%n == 0)
		{
			i-=2; //one above the previous row
			j++;  //back to the previous column
		}
		else if(i == n)
			i = 0; //go to topmost row
		else if(j == -1)
			j = n-1; //go to rightmost column
	}

	cout << "Magic matrix :\n";

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			cout << setw(5) << arr[i][j];
		cout << "\n";
	}

	return 0;
}//End of main()

