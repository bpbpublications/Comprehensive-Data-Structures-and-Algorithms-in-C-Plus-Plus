//Ex6.cpp : Program to remove duplicate elements from an unsorted array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {10,5,20,10,30,5,20,35,5,45};
	int n = 10;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n;  )
		{
			if(arr[i]==arr[j]) //Duplicate found
			{
				n--;
				for(int k=j; k<n; k++)
					arr[k]=arr[k+1];
			}
			else
				j++;	//Continue comparing
		}
	}//End of for

	cout << "After removing duplicates, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()

