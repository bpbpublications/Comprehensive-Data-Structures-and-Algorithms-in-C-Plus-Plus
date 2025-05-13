//Ex41.cpp : Write a recursive function to find whether a string is palindrome or not.
//Ignore the spaces, punctuations marks, uppercase and lowercase differences in string.

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str, int i, int j) 
{
	if(i > j)
		return true;

	if(str[i] == ' ' || str[i]==',' || str[i]=='"'|| str[i]=='.'|| str[i]=='!'|| str[i]=='-')
		return isPalindrome(str, i+1, j);

	if(str[j]==' ' || str[j]==','||  str[j]=='"'|| str[j]=='.'|| str[j]=='!'|| str[j]=='-')
		return isPalindrome(str, i, j-1);

	if(toupper(str[i]) != toupper(str[j]))
		return false;

	return isPalindrome(str,i+1,j-1);

}//End of findChar()

bool isPalindrome(string str)
{
	return isPalindrome(str,0,str.length()-1);
}//End of isPalindrome()

int main()
{
	string str = "A man, a plan, a canal - Panama!";

	cout << "The string is : " << str << "\n";

	if(isPalindrome(str))
		cout << "The string is a palindrome\n";
	else
		cout << "The string is not a palindrome\n";

	return 0;
}//End of main()
