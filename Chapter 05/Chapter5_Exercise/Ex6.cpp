//Ex6.cpp

#include<iostream>
using namespace std;

void func1(int a, int b)
{
	if(a > b)
		return;
	cout << a << " ";
	func1(a+1, b);
}

void func2(int a, int b)
{
	if(a > b)
		return;
	func2(a+1, b);
	cout << a << " ";
}

int main( )
{
	func1(10, 18); 
	cout << "\n";
	func2(10, 18);
	cout << "\n";
}
