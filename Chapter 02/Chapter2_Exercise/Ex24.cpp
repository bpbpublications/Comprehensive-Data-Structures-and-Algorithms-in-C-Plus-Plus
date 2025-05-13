// Ex24.cpp : Write a program to find the maximum sum of k elements subarray in an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {5,3,2,4,1,7,10,9,6,8};
	int n=10, k = 3;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	int maxSum=0, currentSum=0;

	for(int i=0; i<k; i++)
		currentSum += arr[i];

	maxSum = currentSum;

	for(int i=0; i+k<n; i++)
	{
		currentSum = currentSum-arr[i]+arr[i+k];
		if(currentSum > maxSum)
			maxSum = currentSum;
	}

	cout << "Maximum Sum = " << maxSum << "\n";

	return 0;
}//End of main()
