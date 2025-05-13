//P14.cpp : Program to print prime numbers using Sieve of Eratosthenes.

#include<iostream>
using namespace std;

static const int maxSize = 1000;

int main()
{
	int arr[maxSize] = {0};
	int n = 50;
	int p = 2, i;

	while(p*p <= n) 
	{
		for(i=2; i*p<=n; i++) //Cross out all multiples of p
			arr[i*p] = 1;
				
		for(i=p+1; i<=n; i++) //Find next uncrossed
		{
			if(arr[i] == 0)
			{
				p = i;
				break;
			}
		}
	}//End of while

	//Print all uncrossed integers
	for(i=2; i<=n; i++)
	{
		if(arr[i] == 0)
			cout << i << " ";
	}
	cout << "\n";

	return 0;
}//End of main()

