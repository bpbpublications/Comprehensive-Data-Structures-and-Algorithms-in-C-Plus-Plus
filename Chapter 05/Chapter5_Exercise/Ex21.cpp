//Ex21.cpp : Write a recursive function that finds whether a number is perfect or not.

#include<iostream>
using namespace std;

int divisorsSum(int num, int x)
{
	if(x == 1)
	{
		cout << x << "\n";
		return 1;
	}

	if(num%x == 0) //if x is a proper divisor
	{
		cout << x << " ";
		return x + divisorsSum(num,x-1);
	}
	else
		return divisorsSum(num,x-1);
}//End of divisorsAndSum()

int main()
{
	int num = 28;

	if(divisorsSum(num, num/2) == num)
		cout << num << " is a perfect number\n";
	else
		cout << num << " is not a perfect number\n";

	return 0;
}//End of main()