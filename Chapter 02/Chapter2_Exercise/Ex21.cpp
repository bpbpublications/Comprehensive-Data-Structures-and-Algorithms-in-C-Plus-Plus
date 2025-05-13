//Ex21.cpp : Program to rotate left an array by k elements.

#include<iostream>
using namespace std;

static const int maxSize = 30;

//Solution 1 : rotate an array by 1 element k times
void rotate1(int arr[], int n, int k)
{
	for(int i=0; i<k; i++)
	{
		int temp = arr[0];
		for(int i=1; i<n; i++)
			arr[i-1]=arr[i];
		arr[n-1] = temp;
	}

}//End of rotate1()

void reverse(int arr[], int start, int end)
{
	int temp;
	for(int i=start,j=end; i<j; i++,j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}//End of reverse()

//Solution 2 : rotate left by k using reverse
void rotate2(int arr[], int n, int k)
{
	reverse(arr, 0, k-1);
	reverse(arr, k, n-1);
	reverse(arr, 0, n-1);

}//End of rotate2()

int main()
{
	int arr[maxSize] = {5,10,15,20,25,30,35,40,45,50};
	int n=10, k = 5;

	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	rotate1(arr,n,k);

	cout << "After left rotation " << k << " elements, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	rotate2(arr,n,k);

	cout << "Again after left rotation " << k << " elements, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()
