//Ex19.cpp : Program to partition an array such that all the even numbers are on the left side of array and odd numbers on the right 
//side.

#include<iostream>
using namespace std;

static const int maxSize = 30;

void partition(int arr[],int n)
{
	int i=0, j=n-1, temp;
	while(i < j)
	{
		while((arr[i]%2)==0 && i<j) //move right
			i++;
		while((arr[j]%2)!=0 && i<j) //move left
			j--;
		if(i < j) 
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++; j--;
		}
	}//End of while
}//End of partition()

int main()
{
	int arr[maxSize] = {1,2,3,4,5,6,7,8,9,10};
	int n = 10;
	
	cout << "The array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	partition(arr,n);

	cout << "After movement, the array is :\n";
	for(int i=0; i<n; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()
