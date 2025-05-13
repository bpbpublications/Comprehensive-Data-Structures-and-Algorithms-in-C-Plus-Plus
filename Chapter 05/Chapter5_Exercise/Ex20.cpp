//Ex20.cpp : Write a recursive function that displays all the proper divisors of a number and returns their sum.

#include<iostream>
using namespace std;

int divisorsAndSum(int num, int x)
{
	if(x==1)
	{
		cout << x << "\n";
		return 1;
	}

	if(num%x==0) //if x is a proper divisor
	{
		cout << x << " ";
		return x + divisorsAndSum(num,x-1);
	}
	else
		return divisorsAndSum(num,x-1);
}//End of divisorsAndSum()

int main()
{
	int num = 24;
	cout << "Sum of divisors of " << num << " = " << divisorsAndSum(num,num/2) << "\n";

	return 0;
}//End of main()
