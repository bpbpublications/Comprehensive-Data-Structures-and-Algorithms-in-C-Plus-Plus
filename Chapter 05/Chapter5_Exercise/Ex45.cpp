//Ex45.cpp : Write a function to print pyramids of numbers.

#include<iostream>
using namespace std;

void pyramid1(int n)
{
	int i;
	if(n==0)
		return;
    else
	{
		pyramid1(n-1);
		for(i=1; i<= n; i++)
			cout << i << " ";
        cout << "\n";	
	}
}//End of pyramid1()

void pyramid2(int n)
{
	int i;
	if(n==0)
		return;
    else
	{
		for(i=1; i<=n; i++)
			cout << i << " ";
		cout << "\n";	
		pyramid2(n-1);
	}
}//End of pyramid2()

void pyramid3(int n)
{
	int i;
	if(n==0)
		return;
    else
	{
		for(i=n; i>=1; i--)
			cout << i << " ";
        cout << "\n";
		pyramid3(n-1);
	}
}//End of pyramid3()

int main()
{
	pyramid1(4);
	cout << "\n";
	pyramid2(4);
	cout << "\n";
	pyramid3(4);

	return 0;
}//End of main()
