//Ex20.cpp : program to reverse a portion of an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	int start = 2, end = 6;
	int i,j,temp;

	cout << "The array is :\n";
	for(i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	for(i=start-1,j=end-1; i<j; i++,j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	cout << "After reversing, the array is :\n";
	for(i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()
