//Ex7.cpp : Modify the bubble sort given in chapter so that in each pass the sorting is done in both directions.

#include<iostream>
using namespace std;

static const int maxSize = 30;

void bubbleSort(int arr[], int n)
{
	int temp, xchanges;

    for(int i=0; i<n-1 ;i++)
	{
		xchanges=0;
		for(int j=0; j<n-1-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				xchanges++;
			}
		}

		if(xchanges == 0) //If list is sorted
			break;
		
		xchanges=0;
		for(int j=n-1-i; j>i; j--)
		{
			if(arr[j] < arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				xchanges++;
			}
		}

		if(xchanges == 0) //If list is sorted
			break;
	
		for(int k=0; k<n; k++)
			cout << arr[k] << " ";
		cout << "\n";
	}

}//End of bubbleSort()

int main()
{
	int arr[maxSize] = {40, 20, 50, 60, 30, 10, 90, 97, 70, 80};
	int n = 10;

	cout << "Unsorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n\n";

	bubbleSort(arr,n);
	
	cout << "\nSorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

}//End of main()
