//Ex38.cpp : Write a recursive function to return the index of first occurrence of a character in a string.

#include<iostream>
#include<string>
using namespace std;

int findChar(string str, char ch, int i) 
{
	if(str.length() == i)
		return -1;

	if(str[i] == ch)
		return i;

	return findChar(str,ch,i+1);

}//End of findChar()

int findChar(string str,char ch)
{
	return findChar(str,ch,0);
}//End of findChar()

int main()
{
	string str = "This is coding";
	char ch = 'i';

	cout << "String is : " << str << ", character is : " << ch << "\n";

	cout << "Index is : " << findChar(str,ch) << "\n";

	return 0;
}//End of main()

