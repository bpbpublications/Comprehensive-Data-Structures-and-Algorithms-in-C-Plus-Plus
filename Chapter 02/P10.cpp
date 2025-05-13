//P10.cpp : Program to rotate an array left by 1 element.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {10,20,30,40,50};
	int n=5;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	int temp = arr[0];
	for(int i=1; i<n; i++)
		arr[i-1]=arr[i];
	arr[n-1] = temp;

	cout << "After left rotation, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()

