//Ex13.cpp

#include<iostream>
using namespace std;

int func(char *s, char a)
{ 
	if(*s == '\0')
		return 0;
	if(*s == a)
		return 1 + func(s+1, a); 
	return func(s+1, a); 
}

int main() 
{ 
	char str[100] = "data structures and algorithms";
	char a = 't';

	cout << func(str, a) << "\n";
}
