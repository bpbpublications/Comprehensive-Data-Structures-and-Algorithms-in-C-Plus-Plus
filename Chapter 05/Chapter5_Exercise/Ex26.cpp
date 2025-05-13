//Ex26.cpp : Write a recursive function that displays a positive integer in words.

#include<iostream>
using namespace std;

void integerToWords(int n) 
{ 
	if(n==0)
		return;

	integerToWords(n/10);

	switch(n%10)
	{
		case 0: cout << "zero "; break;
		case 1: cout << "one "; break;
		case 2: cout << "two "; break;
		case 3: cout << "three "; break;
		case 4: cout << "four "; break;
		case 5: cout << "five "; break;
		case 6: cout << "six "; break;
		case 7: cout << "seven "; break;
		case 8: cout << "eight "; break;
		case 9: cout << "nine "; break;
	}
}//End of integerToWords()

int main()
{
	int num = 12340;
	cout << num << " in words :\n";
	integerToWords(num);
	cout << "\n";

	return 0;
}//End of main()
