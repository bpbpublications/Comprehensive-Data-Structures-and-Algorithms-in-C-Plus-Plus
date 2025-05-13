//Ex4.cpp : Program to reverse only first k elements of an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {95,67,32,35,44,65,59,17,20,37};
	int n = 10;
	int k = 5;
	int i,j,temp;

	cout << "The array is :\n";
	for(i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	for(i=0,j=k-1; i<j; i++,j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	cout << "After reverse of first " << k << " elements, the array is :\n";
	for(i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()

