//Ex2.cpp : Program to find the difference of the largest and smallest elements of an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {2,5,4,1,8,9,11,6,3,7};
	int n = 10;
	int smallest, largest;

	smallest = largest = arr[0];

	for(int i=1; i<n; i++)
	{
		if(arr[i] < smallest)
			smallest = arr[i];
		if(arr[i] > largest)
			largest = arr[i];
	}

	cout << "Difference of largest(" << largest << ") and smallest(" << smallest << ") is : " << largest-smallest << "\n";

	return 0;
}//End of main()

