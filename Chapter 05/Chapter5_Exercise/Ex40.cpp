//Ex40.cpp : Write a recursive function to find whether a string is palindrome or not.

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str, int i, int j) 
{
	if(i > j)
		return true;

	if(str[i] != str[j])
		return false;

	return isPalindrome(str,i+1,j-1);

}//End of isPalindrome()

bool isPalindrome(string str)
{
	return isPalindrome(str,0,str.length()-1);
}//End of isPalindrome()

int main()
{
	string str = "abcba";

	cout << "The string is : " << str << "\n";

	if(isPalindrome(str))
		cout << "The string is a palindrome\n";
	else
		cout << "The string is not a palindrome\n";

	return 0;
}//End of main()