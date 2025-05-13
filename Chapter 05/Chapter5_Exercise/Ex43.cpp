//Ex43.cpp : Write a function to convert a string of numbers to an integer.

#include<iostream>
#include<string>
using namespace std;

int stringToNumber(string str, int num, int i) 
{ 
	if(str.length() == i)
		return num;
	
	num = num*10 + str[i]-'0';
	
	return stringToNumber(str,num,i+1);

}//End of stringToNumber()

int stringToNumber(string str) 
{
	return stringToNumber(str,0,0);
}//End of stringToNumber()

int main()
{
	string str = "12340";
	cout << "String " << str << " in number : " << stringToNumber(str) << "\n";

	return 0;
}//End of main()
