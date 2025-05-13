//Ex17.cpp : Write a program to sort a list of strings using bubble sort.

#include<iostream>
#include<string>
using namespace std;

static const int maxSize = 30;

void bubbleSort(string arr[], int n)
{
	string temp;
	int xchanges;

	for(int i=0; i<n-1; i++)
	{
		xchanges = 0;
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
	}//End of for
}//End of bubbleSort()

int main()
{
	string arr[maxSize] = {"Newyork", "Bangalore", "Tokyo", "Paris", "Lucknow"};
	int n = 5;

	cout << "Unsorted list is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	bubbleSort(arr,n);
	
	cout << "Sorted list is :\n"; 
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

}//End of main()

