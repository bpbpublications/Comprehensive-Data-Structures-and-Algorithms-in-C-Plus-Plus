//Ex22.cpp : Write a recursive function to find the sum of all even numbers in an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int sumEven(int arr[], int n)
{
	if(n == 0)
		return 0;
	
	if(arr[n-1]%2 == 0)
		return arr[n-1] + sumEven(arr, n-1);

	sumEven(arr, n-1);
}//End of sumEven()

int main()
{
	int arr[maxSize] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	
	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	cout << "Sum of even numbers = " << sumEven(arr, n) << "\n";

	return 0;
}//End of main()