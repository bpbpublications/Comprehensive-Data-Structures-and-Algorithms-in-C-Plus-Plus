//Ex9.cpp

#include<iostream>
using namespace std;

int func(int n) 
{ 
	return (n) ? n%10 + func(n/10) : 0; 
}

int main() 
{ 
	cout << func(14837) << "\n";
}
