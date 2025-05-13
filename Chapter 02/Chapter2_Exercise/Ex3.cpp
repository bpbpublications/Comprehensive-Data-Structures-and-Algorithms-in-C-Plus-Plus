//Ex3.cpp : Program to find the largest and second largest elements of an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {2,5,4,1,8,9,11,6,3,7};
	int n = 10;
	int largest, secondLargest;

	largest = secondLargest = arr[0];

	for(int i=1; i<n; i++)
	{
		if(arr[i] > largest)
		{
			secondLargest = largest;
			largest = arr[i];
		}
	}

	cout << "Largest : " << largest << ", second largest : " << secondLargest << "\n";

	return 0;
}//End of main()

