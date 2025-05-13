//Ex39.cpp : Write a recursive function to return the index of last occurrence of a character in a string.

#include<iostream>
#include<string>
using namespace std;

int findChar(string str, char ch, int i) 
{
	if(i == 0)
		return -1;

	if(str[i-1] == ch)
		return i-1;

	return findChar(str,ch,i-1);

}//End of findChar()

int findChar(string str,char ch)
{
	return findChar(str,ch,str.length());
}//End of findChar()

int main()
{
	string str = "This is coding";
	char ch = 'i';

	cout << "String is : " << str << ", character is : " << ch << "\n";

	cout << "Index is : " << findChar(str,ch) << "\n";

	return 0;
}//End of main()