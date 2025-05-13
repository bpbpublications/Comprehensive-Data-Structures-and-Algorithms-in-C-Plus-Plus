//Ex1.cpp : Program to exchange adjacent elements of an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {40, 20, 50, 60, 30, 10, 90, 97, 70, 80};
	int n = 10;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	int temp;
	for(int i=0; i<n-1; i=i+2)
	{
		temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
	}

	cout << "After exchanging adjacent elements, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()

