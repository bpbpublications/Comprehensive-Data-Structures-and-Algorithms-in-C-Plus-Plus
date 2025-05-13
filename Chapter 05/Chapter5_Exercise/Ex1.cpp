// Ex1.cpp

#include<iostream>
using namespace std;

int func1(int a, int b)
{
	if(a > b)
		return 0;
	return b + func1(a, b-1);
}

int func2(int a, int b)
{
	if(a > b)
		return 0;
	return a + func2(a+1, b);
}

int main()
{
	cout << func1(3, 8) << " " << func2(3, 8) << "\n";
}
