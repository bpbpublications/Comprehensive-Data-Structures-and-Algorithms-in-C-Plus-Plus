//Ex2.cpp : Write recursive program for sorting an array through selection sort.

#include<iostream>
using namespace std;

static const int maxSize = 30;

void selectionSort(int arr[], int start, int end)
{
	int min, temp; 

	if(start >= end)
		return;
  
	min = start;
	for(int j=start+1; j<=end; j++)
	{
		if(arr[min] > arr[j])
			min=j ;
	}

	temp = arr[start];
	arr[start] = arr[min];
	arr[min] = temp;        

	selectionSort(arr, start+1, end);

}//End of selectionSort()

void selectionSort(int arr[], int n)
{
	selectionSort(arr, 0, n-1);
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
