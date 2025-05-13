//Ex3.cpp : Write a program to sort an array in descending order using selection sort.

#include<iostream>
using namespace std;

static const int maxSize = 30;

void selectionSort(int arr[], int n)
{
	int max, temp;

	for(int i=0; i<n-1; i++)
	{
		//Find the index of largest element
		max = i;
		for(int j=i+1; j<n ; j++)
		{
			if(arr[max] < arr[j])
				max = j;
		}

		if(i != max)
		{
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp ;
		}
	}//End of for
}//End of selectionSort()

int main()
{
	int arr[maxSize] = {82, 42, 49, 8, 25, 52, 36, 93, 59, 15};
	int n = 10;

	cout << "Unsorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	selectionSort(arr,n);
	
	cout << "Sorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

}//End of main()
