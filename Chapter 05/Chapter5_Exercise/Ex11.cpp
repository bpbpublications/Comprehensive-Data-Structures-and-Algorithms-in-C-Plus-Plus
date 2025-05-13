//Ex11.cpp

#include<iostream>
using namespace std;

int func(int arr[], int size)
{
	if(size == 0)
		return 0;
	else if(arr[size-1]%2 == 0)
		return 1 + func(arr, size-1);
	else
		return func(arr, size-1);
}

int main( )
{
	int arr[10] = {1,2,3,4,8,10};
	cout << func(arr, 6) << "\n";
}
