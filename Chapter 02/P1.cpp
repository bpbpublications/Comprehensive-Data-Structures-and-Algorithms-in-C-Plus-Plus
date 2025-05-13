//P1.cpp : Program to display the array elements.

#include <iostream>
using namespace std;

int main()
{
	int arr[5] = {10, 20, 30, 40, 50};

	cout << "The array elements are :\n";
	for(int i=0; i<5; i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}//End of main()

