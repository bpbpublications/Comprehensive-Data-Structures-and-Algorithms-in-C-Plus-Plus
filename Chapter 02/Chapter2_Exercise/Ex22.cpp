//Ex22.cpp : Write a program to display intersection of two arrays, i.e. it contains only the elements which are common to both the arrays.

#include<iostream>
using namespace std;

void intersectionArrays(int arr1[],int n1, int arr2[], int n2)
{
	for(int i=0; i<n1; i++)
	{
		for(int j=0; j<n2; j++)
		{
			if(arr1[i] == arr2[j])
			{
				cout << arr1[i] << " ";
				break;
			}
		}
	}
	cout << "\n";
}//End of intersectionArrays()

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

	cout << "Intersection of Array 1 and Array 2 is :\n";
	intersectionArrays(arr1,n1,arr2,n2);

	return 0;
}//End of main()
