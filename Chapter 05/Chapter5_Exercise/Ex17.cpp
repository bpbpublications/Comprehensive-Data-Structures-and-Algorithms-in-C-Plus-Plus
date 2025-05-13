//Ex17.cpp : Write a recursive function to add array of n numbers.

#include<iostream>
using namespace std;

int	addNumbers(int arr[], int n)
{
	if(n == 0)
	    return 0;
	else
	    return arr[n-1] + addNumbers(arr, n-1);
}//End of addNumbers()

int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;

	cout << "Array numbers :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	cout << "Sum of array numbers = " << addNumbers(arr,10) << "\n";

	return 0;
}//End of main()

