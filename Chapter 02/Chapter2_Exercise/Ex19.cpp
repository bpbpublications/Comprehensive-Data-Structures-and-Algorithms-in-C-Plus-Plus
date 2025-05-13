//Ex19.cpp : Program to find the kth smallest element in an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {5,15,10,25,30,35,20,40,50,45};
	int n = 10, k = 5;
	int min, temp;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

    for(int i=0; i<k; i++) //Selection sort upto k only
	{
		min=i;
		for(int j=i+1; j<n; j++)
		{
			if(arr[min] > arr[j])
				min=j ;
		}
		if(i!=min)
		{
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}

	cout << k << "th smallest element is : " << arr[k-1] << "\n";

	return 0;
}//End of main()
