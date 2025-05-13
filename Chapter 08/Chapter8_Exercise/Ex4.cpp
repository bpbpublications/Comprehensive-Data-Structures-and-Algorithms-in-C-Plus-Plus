//Ex4.cpp : Modify the selection sort program given in the chapter so that in each pass the larger element moves towards the end.

#include<iostream>
using namespace std;

static const int maxSize = 30;

void selectionSort(int arr[], int n)
{
	int max, temp;

	for(int i=n-1; i>0; i--)
	{
		//Find the index of largest element
		max=i;
		for(int j=i-1; j>=0; j--)
		{
			if(arr[max] < arr[j])
				max=j ;
		}

		if(i!=max)
		{
			temp = arr[i];
			arr[i] = arr[max];
			arr[max] = temp ;
		}

		for(int k=0; k<n; k++)
			cout << arr[k] << " ";
		cout << "\n";
	}//End of for
}//End of selectionSort()

int main()
{
	int arr[maxSize] = {82, 42, 49, 8, 25, 52, 36, 93, 59, 15};
	int n = 10;

	cout << "Unsorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n\n";

	selectionSort(arr,n);
	
	cout << "\nSorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

}//End of main()
