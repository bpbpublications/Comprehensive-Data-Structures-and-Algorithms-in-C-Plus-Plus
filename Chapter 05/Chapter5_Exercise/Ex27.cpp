//Ex27.cpp : Write a recursive function that reverses an integer.

#include<iostream>
using namespace std;

int reverse(int n, int num) 
{ 
	if(n == 0)
		return num;

	num = num * 10 + n%10 ;
	reverse(n/10, num);

}//End of reverse()

int reverse(int n)
{
	return reverse(n, 0);
}

int main()
{
	int num = 5678;
	cout << "Reverse of " << num << " is : " << reverse(num) << "\n";

	return 0;
}//End of main()
