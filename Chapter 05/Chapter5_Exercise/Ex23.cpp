//Ex23.cpp : Write a recursive function that finds the sum of all elements of an array by repeatedly partitioning it into two almost equal parts.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int sum(int arr[], int low, int high)
{
	int mid, left, right;
	if(low == high)
		return arr[low];

	mid = (low+high)/2;
	left = sum(arr,low,mid);
	right = sum(arr,mid+1,high);

	return (left+right);
}//End of sum()

int main()
{
	int arr[maxSize] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	
	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	cout << "Sum = " << sum(arr, 0, n-1) << "\n";

	return 0;
}//End of main()
