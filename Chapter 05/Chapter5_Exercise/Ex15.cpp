//Ex15.cpp

#include<iostream>
using namespace std;

int func(int arr[], int size)
{
	int m;
	if(size == 1)
		return arr[0];
    m = func(arr, size-1);
	if(arr[size-1] < m )
		return arr[size-1];
	else
		return m;
}

int main( )
{
	int arr[10] = {2,3,1,4,6,34};
	cout << func(arr, 6) << "\n";
}
