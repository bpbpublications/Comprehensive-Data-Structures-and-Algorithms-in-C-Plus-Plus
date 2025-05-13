//P5.cpp : Program to understand the effect of passing an array to a function.

#include<iostream>
using namespace std;

void func(int val[])
{
	int sum=0;

	for(int i=0; i<6; i++)
	{
		val[i] = val[i]*val[i];
		sum += val[i];
	}

	cout << "Sum of square = " << sum << "\n";

}//End of func()

int main()
{
	int arr[6] = {1,2,3,4,5,6};

	cout << "The array is :\n";
	for(int i=0; i<6; i++)
		cout << arr[i] << " ";
	cout << "\n";

	func(arr);

	cout << "Now the array is :\n";
	for(int i=0; i<6; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()

