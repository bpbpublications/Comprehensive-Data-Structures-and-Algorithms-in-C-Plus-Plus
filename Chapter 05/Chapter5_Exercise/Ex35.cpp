//Ex35.cpp : Write a recursive function to count the number of vowels in a string.

#include<iostream>
#include<string>
using namespace std;

int countVowels(string str, int i) 
{ 
	if(str.length() == i)
		return 0;

	switch(str[i])
    { 
	    case 'A': case 'a':
		case 'E': case 'e':
		case 'I': case 'i':
		case 'O': case 'o':
		case 'U': case 'u':
             return 1 + countVowels(str,i+1);
		default:
             return countVowels(str,i+1);
    }
}//End of countVowels()

int countVowels(string str)
{
	return countVowels(str,0);
}//End of countVowels()

int main()
{
	string str = "This is recursion";

	cout << "String is : " << str << "\n";
	cout << "Number of vowels : " << countVowels(str) << "\n";

	return 0;
}//End of main()
