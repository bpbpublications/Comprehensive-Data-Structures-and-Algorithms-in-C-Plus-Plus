//Ex5.cpp : Program to check whether all the elements of an array are distinct.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {10,5,20,15,30,25,40,35,50,45};
	int n = 10;
	bool duplicateFound = false;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(arr[i] == arr[j])
				duplicateFound = true;

	if(duplicateFound)
		cout << "All the elements of array are not distinct.\n";
	else
		cout << "All the elements of array are distinct.\n";

	return 0;
}//End of main()

