//P2.cpp : Program to find the smallest and largest number in an array.

#include<iostream>
using namespace std;

int main()
{
	int arr[10] = {2,5,4,1,8,9,11,6,3,7};
	int small, large;

	small = large = arr[0];

	for(int i=1; i<10; i++)
	{
		if(arr[i] < small)
			small = arr[i];
		if(arr[i] > large)
			large = arr[i];
	}

	cout << "Smallest = " << small << ", Largest = " << large << "\n";

	return 0;
}//End of main()

