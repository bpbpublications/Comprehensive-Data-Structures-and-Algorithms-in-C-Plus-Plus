//Ex24.cpp : Write a recursive function to reverse the elements of an array.

#include<iostream>
using namespace std;

static const int maxSize = 30;

void reverse(int arr[], int low, int high)
{
	int temp;

	if(low >= high)
		return;

	temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;

	reverse(arr, low+1, high-1);

}//End of reverse()

int main()
{
	int arr[maxSize] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	
	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	reverse(arr, 0, n-1);

	cout << "After reverse, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()