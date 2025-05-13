//Ex8.cpp

#include<iostream>
using namespace std;

int count(int n)
{
	if(n == 0) 
		return 0;
	else 
		return 1 + count(n/10);
}

int main()
{
	cout << count(17243) << "\n";
}
