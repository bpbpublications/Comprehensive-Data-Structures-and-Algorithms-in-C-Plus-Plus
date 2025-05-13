//Ex7.cpp : Program to remove duplicate elements from a sorted array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {5,10,15,15,15,30,35,35,45,50};
	int n = 10;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	int k, ndup;
	for(int i=0; i<n; i++)
	{
		if(arr[i]==arr[i+1])
		{
			k=i+1;
			while(k<n && arr[k]==arr[k+1])
				k++;
			//Duplicates of arr[i] start at i+1 and end at k
			ndup=k-i;	//Number of duplictaes of arr[i]
			for(k=i+1; k<n; k++)
				arr[k]=arr[k+ndup];
			n=n-ndup;
		}
	}//End of for

	cout << "After removing duplicates, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()
