//P3.cpp : Program to reverse the elements of an array.

#include<iostream>
using namespace std;

int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int i,j,temp;

	cout << "The array is :\n";
	for(i=0; i<10; i++)
		cout << arr[i] << " ";
	cout << "\n";

	for(i=0,j=9; i<j; i++,j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	cout << "After reversing, the array is :\n";
	for(i=0; i<10; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()

