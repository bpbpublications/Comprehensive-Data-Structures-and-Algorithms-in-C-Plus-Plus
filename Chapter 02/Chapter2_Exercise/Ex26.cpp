// Ex26.cpp : Write a program to find all two array elements whose sum is equal to k.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {5,15,10,25,30,35,20,40,50,45};
	int n = 10, k = 45;
	int min, temp;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[j] == k-arr[i])
			{
				cout << "arr[" << i << "](" << arr[i] << ") + arr[" << j << "](" << arr[j] << ") = " << k << "\n";
			}
		}
	}

	return 0;
}//End of main()
