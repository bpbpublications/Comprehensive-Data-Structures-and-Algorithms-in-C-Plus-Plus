//Ex28.cpp : Write a recursive function to find remainder when a positive integer a is divided by positive integer b.

#include<iostream>
using namespace std;

int getRemainder(int a, int b)
{
	if(a<b) 
		return a;
	else 
		return getRemainder(a-b, b);
}//End of getRemainder()

int main()
{
	int a = 24, b = 5;

	cout << "Remainder of " << a << "/" << b << " = " << getRemainder(a,b) << "\n";

	return 0;
}//End of main()

