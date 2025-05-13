//Ex2.cpp

#include<iostream>
using namespace std;

int func(int a, int b)
{
	if(a > b)
		return 1000;
	return a + func(a+1, b);
}

int main()
{
	cout << func(3, 8) << "\n";
}
