//Ex13.cpp : Modify the insertion sort algorithm to use binary search instead of linear search.

#include<iostream>
using namespace std;

static const int maxSize = 30;

void insertionSort(int arr[], int n)
{
	int i,j,k;
	int low, up, mid;

	for(i=1; i<n; i++)
	{
		k=arr[i]; //k is to be inserted at proper place
	    low=0, up=i-1;
        while(low <= up)
	    {   
			mid = (low+up)/2;
			if(k >= arr[mid])
				low = mid+1;	
			else if(k < arr[mid])
				up = mid-1;		
		}

		for(j=i-1; j>=low; j--)
			arr[j+1]=arr[j];
		arr[j+1]=k;

	}//End of for

}//End of insertionSort()

int main()
{
	int arr[maxSize] = {82, 42, 49, 8, 25, 52, 36, 93, 59, 15};
	int n = 10;

	cout << "Unsorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	insertionSort(arr,n);
	
	cout << "Sorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

}//End of main()
