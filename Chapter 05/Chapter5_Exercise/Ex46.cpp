//Ex46.cpp : Write a recursive function that returns nth triangular number.

#include<iostream>
using namespace std;

int triangularNumber(int n)
{
	if(n == 1)
		return 1;
	return n + triangularNumber(n-1);
}//End of triangularNumber()

int main()
{
	int n = 4;

	cout << triangularNumber(n) << "\n";

	return 0;
}//End of main()
