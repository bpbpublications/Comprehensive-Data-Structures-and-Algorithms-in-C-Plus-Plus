//Ex14.cpp

#include<iostream>
using namespace std;

void func1(int n)
{
	int i;
	if(n == 0)
		return;
    for(i=1; i<=n; i++)
		cout << "*";
	cout << "\n";
	func1(n-1);
}

void func2(int n)
{
	int i;
	if(n == 0)
		return;
    func2(n-1);
	for(i=1; i<=n; i++)
		cout << "*";
    cout << "\n";	
}

int main( )
{
	func1(4);
	cout << "\n";
	func2(4);
}
