//Ex4.cpp

#include<iostream>
using namespace std;

int func(int a, int b)
{
	if(a == b)
		return a;
	return a + b + func(a+1, b-1);
}

int main()
{
	cout << func(4, 8) << "\n";
	cout << func(3, 8) << "\n";
}
