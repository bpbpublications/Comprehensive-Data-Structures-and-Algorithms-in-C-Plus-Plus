//Ex29.cpp : Write a recursive function to find quotient when a positive integer a is divided by positive integer b.

#include<iostream>
using namespace std;

int getQuotient(int a, int b)
{
	if(a<b) 
		return 0;
	else 
		return 1+getQuotient(a-b, b);
}//End of getQuotient()

int main()
{
	int a = 24, b = 5;

	cout << "Quotient of " << a << "/" << b << " = " << getQuotient(a,b) << "\n";

	return 0;
}//End of main()
