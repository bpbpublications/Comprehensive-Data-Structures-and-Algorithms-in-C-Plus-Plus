//P11.cpp : Write a program that scans a one-dimensional array from left to right and compares all adjacent elements Any two adjacent 
//elements arr[j] and arr[j+1] should be exchanged if arr[j] is greater than arr[j+1]. This procedure will always place the biggest 
//element at the last position. Count the total number of exchanges done.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {40, 20, 50, 60, 30, 10, 90, 97, 70, 80};
	int n = 10, xchanges = 0;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	int temp;
	for(int i=0; i<n-1; i++)
	{
		if(arr[i]>arr[i+1])
		{
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			xchanges++;
		}
	}

	cout << "After exchanges, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	cout << "Total number of exchanges = " << xchanges << "\n";

	return 0;
}//End of main()

