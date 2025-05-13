// Ex23.cpp : Write a program to display union of two arrays i.e. all elements of both arrays and if an element is repeated in both arrays, then display it only once.

#include<iostream>
using namespace std;

bool isPresent(int data, int arr1[], int n1)
{
	for(int i=0; i<n1; i++)
	{
		if(arr1[i] == data)
			return true;
	}

	return false;
}//End of isPresent()

void unionArrays(int arr1[],int n1, int arr2[], int n2)
{
	for(int i=0; i<n1; i++)
		cout << arr1[i] << " ";

	for(int i=0; i<n2; i++)
	{
		if(!isPresent(arr2[i], arr1, n1))
			cout << arr2[i] << " ";
	}
	cout << "\n";
}//End of unionArrays()

int main()
{
	int arr1[] = {10, 20, 30, 40, 50, 60};
	int n1 = 6;

	int arr2[] = {10, 15, 30, 35, 50, 60};
	int n2 = 6;

	cout << "Array 1 :\n";
	for(int i=0; i<6; i++)
		cout << arr1[i] << " ";
	cout << "\n";

	cout << "Array 2 :\n";
	for(int i=0; i<6; i++)
		cout << arr2[i] << " ";
	cout << "\n";

	cout << "Union of Array 1 and Array 2 is :\n";
	unionArrays(arr1,n1,arr2,n2);

	return 0;
}//End of main()
