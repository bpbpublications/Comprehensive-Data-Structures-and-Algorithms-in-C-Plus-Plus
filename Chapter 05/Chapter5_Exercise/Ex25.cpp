//Ex25.cpp : Write a recursive function to find whether the elements of an array are in strict ascending order or not.

#include<iostream>
using namespace std;

static const int maxSize = 30;

bool isAscending(int arr[],int n)
{
	if(n==1)
		return true;
	
	if(arr[0] >= arr[1])
		return false;
	
	isAscending(arr+1, n-1);
}//End of isAscending()

int main()
{
	int arr[maxSize] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	
	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	if(isAscending(arr, n))
		cout << "Array elements are in strict ascending order.\n";
	else
		cout << "Array elements are not in strict ascending order.\n";

	return 0;
}//End of main()


