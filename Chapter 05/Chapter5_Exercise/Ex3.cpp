// Ex3.cpp

#include<iostream>
using namespace std;

int func(int a)
{
	if(a == 10)
		return a;
	return a + func(a+1);
}

int func1(int a)
{
	if(a == 0)
		return a;
	return a + func1(a+1);
}

int main()
{
	cout << func(6) << "\n";
	cout << func1(6) << "\n";
}
