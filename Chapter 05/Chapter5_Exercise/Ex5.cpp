//Ex5.cpp

#include<iostream>
using namespace std;

void func1(int a, int b)
{
	if(a > b)
		return;
	cout << b << " ";
	func1(a, b-1);
}

void func2(int a, int b)
{
	if(a > b)
		return;
    func2(a, b-1);
	cout << b << " ";
}

int main()
{
	func1(10, 18); 
	cout << "\n";
	func2(10, 18);
	cout << "\n";
}
