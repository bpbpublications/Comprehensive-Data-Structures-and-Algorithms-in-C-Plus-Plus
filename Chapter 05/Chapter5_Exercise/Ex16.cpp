//Ex16.cpp

#include<iostream>
using namespace std;

int func(int arr[], int low, int high)
{
	int mid, left, right;
	if(low == high)
		return arr[low];
    mid = (low+high)/2;
	left = func(arr, low, mid);
	right = func(arr, mid+1, high);
    if(left < right)
		return left;
	else
		return right;
}

int main( )
{
	int arr[6] = {3,4,2,11,8,10};
	cout << func(arr, 0, 5) << "\n";
}
