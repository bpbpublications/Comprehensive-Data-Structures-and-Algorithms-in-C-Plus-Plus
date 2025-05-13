//Ex37.cpp : Write a recursive function to reverse a string.

#include<iostream>
#include<string>
using namespace std;

string reverse(string str, int i, int j) 
{ 
	if(i > j)
		return str;

	char temp = str[i];
	str[i] = str[j];
	str[j] = temp;

	return reverse(str, i+1, j-1);

}//End of reverse()

string reverse(string str)
{
	return reverse(str,0,str.length()-1);
}//End of reverse()

int main()
{
	string str = "Bangalore";

	cout << "String is : " << str << "\n";

	cout << "After reverse, " << "the string is : " << reverse(str) << "\n";

	return 0;
}//End of main()
