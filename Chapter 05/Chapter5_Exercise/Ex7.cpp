//Ex7.cpp

#include<iostream>
using namespace std;

int func(int a, int b) 
{
	if(b == 0)
		return 0;
	if(b == 1)
		return a;
	return a + func(a, b-1);
}

int main()
{
	cout << func(3, 8) << " ";
	cout << func(3, 0) << " ";
	cout << func(0, 3) << "\n";
}
