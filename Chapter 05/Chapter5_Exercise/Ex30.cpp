//Ex30.cpp : Write a recursive function to compute a^n.

#include<iostream>
using namespace std;

int compute(int a, int b)
{
	if(b==0) 
		return 1;
	else if (b%2==0) 
		return compute(a*a, b/2);
	else 
		return a * compute(a*a, (b-1)/2);
}//End of compute()

int main()
{
	int a = 2, b = 5;

	cout << a << "^" << b << " = " << compute(a,b) << "\n";

	return 0;
}//End of main()
