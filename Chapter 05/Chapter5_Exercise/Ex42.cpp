//Ex42.cpp : Write a function to convert a positive integer to string.

#include<iostream>
#include<string>
using namespace std;

string numberToString(string str, int n, int i) 
{ 
	if(n==0)
		return str;
	
	str.insert(str.begin(), 1, char(n%10+'0'));
	
	return numberToString(str,n/10,i+1);

}//End of numberToString()

string numberToString(int n) 
{
	string str;
	return numberToString(str,n,0);
}//End of numberToString()

int main()
{
	int num = 12340;
	cout << num << " in string : " << numberToString(num) << "\n";

	return 0;
}//End of main()
