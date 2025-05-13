// Ex25.cpp : Write a program to find the if left side sum of array elements are equal to the right side sum of array elements.

#include<iostream>
using namespace std;

static const int maxSize = 30;

int main()
{
	int arr[maxSize] = {9,4,3,1,5,6,2,8,7,11};
	int n=10, k = 3;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	int leftSum=0, rightSum=0;
	int i;

	for(i=0; i<n; i++)
		rightSum += arr[i];

	for(i=0; i<n; i++)
	{
		leftSum += arr[i];
		rightSum -= arr[i];
		
		if(leftSum == rightSum)
			break;
	}

	if(leftSum == rightSum)
		cout << "Sum of arr[0.." << i << "] = Sum of arr[" << i+1 << ".." << n-1 << "]\n";
	else
		cout << "No where in array sum of left side elements are equal to sum of right side elements\n";

	return 0;
}//End of main()
