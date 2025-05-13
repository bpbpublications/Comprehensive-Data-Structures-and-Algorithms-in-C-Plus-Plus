//Ex6.cpp : Modify the bubble sort program so that the smallest element is bubbled up in each pass.

#include<iostream>
using namespace std;

static const int maxSize = 30;

void bubbleSort(int arr[], int n)
{
	int temp, xchanges;

	for(int i=0; i<n-1; i++)
	{
		xchanges=0;
		for(int j=n-1; j>i; j--)
		{
			if(arr[j] < arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
				xchanges++;
			}
		}

		if(xchanges==0) //If list is sorted
			break;

		for(int k=0; k<n; k++)
			cout << arr[k] << " ";
		cout << "\n";

	}//End of for
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
