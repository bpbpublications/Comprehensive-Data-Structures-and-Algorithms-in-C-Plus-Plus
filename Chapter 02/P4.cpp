//P4.cpp : Program to pass array elements to a function.

#include<iostream>
using namespace std;

void checkEvenOdd(int num)
{
	if(num%2 == 0)
		cout << num << " is even\n";
	else
		cout << num << " is odd\n";
}//End of checkEvenOdd()

int main()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};

	for(int i=0; i<10; i++)
		checkEvenOdd(arr[i]);

	return 0;
}//End of main()

