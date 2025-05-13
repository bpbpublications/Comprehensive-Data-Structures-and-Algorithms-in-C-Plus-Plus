//Ex8.cpp : Program to find the most frequent element in a sorted array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {5,5,10,15,15,15,30,35,35,50};
	int n = 10;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	int maxTimes = 0, count;
	int mfElement, element;

	mfElement=arr[0];
	
	int i=0;
	while(i <= n-1)
	{
			element = arr[i];
			count = 0;	
			while(arr[i]==element && i<n)
			{
				count++;
				i++;
			}
			if(count > maxTimes)
			{
				mfElement=element;
				maxTimes=count;
			}
	}//End of while

	cout << mfElement << " occurs " << maxTimes << " times.\n";

	return 0;
}//End of main()

