//Ex31.cpp : Write a recursive function to multiply two numbers by Russian peasant method.

#include<iostream>
using namespace std;

int multiplication(int a, int b) 
{
	if(a==0) //if we write if(a==1) return b; then 0 * b can not be computed, so this condition
		return 0;

	if(a%2!=0) //if a is odd
        return b + multiplication(a/2, b*2);

    return multiplication(a/2, b*2);
}//End of multiplication()

int main()
{
	int a = 19, b = 25;

	cout << a << "*" << b << " by russian peasant method = " << multiplication(a,b) << "\n";

	return 0;
}//End of main()
