//Ex10.cpp

#include<iostream>
using namespace std;

int count(long int n, int d)
{
	if(n == 0) 
		return 0;
	else if(n%10 == d)
		return 1 + count(n/10, d);
	else
		return count(n/10, d);
}

int main()
{
	cout << count(123212, 2) << "\n";
}
