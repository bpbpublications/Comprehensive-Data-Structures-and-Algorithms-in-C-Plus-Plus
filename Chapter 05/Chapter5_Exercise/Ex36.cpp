//Ex36.cpp : Write a recursive function to replace each occurrence of a character by another character in a string.

#include<iostream>
#include<string>
using namespace std;

string replaceCharInStr(string str, char a, char b, int i) 
{ 
	if(str.length() == i)
		return str;

	if(str[i] == a)
		str[i] = b;

	return replaceCharInStr(str,a,b,i+1);

}//End of replaceCharInStr()

string replaceCharInStr(string str, char a, char b)
{
	return replaceCharInStr(str,a,b,0);
}//End of replaceCharInStr()

int main()
{
	string str = "This is recursion";

	cout << "String is : " << str << "\n";
	char a = 'i', b = 'e';

	cout << "After replacing " << a << " with " << b << ", the string is : " << replaceCharInStr(str, a, b) << "\n";

	return 0;
}//End of main()
