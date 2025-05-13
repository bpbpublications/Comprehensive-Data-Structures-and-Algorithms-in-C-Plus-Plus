//Ex19.cpp : Write a recursive function to count all the prime numbers between numbers a and b (both inclusive).

#include<iostream>
using namespace std;

bool isPrime(int n)
{
	if(n < 2)
		return false;

	for(int i=2; i<=(n/2); i++)	
		if(n%i == 0)
		    return false;

	return true;
}//End of isPrime()

int countPrimes(int a, int b)
{
	if(a > b)
		return 0;
	if(isPrime(b))
	{
		cout << b << " ";
		return 1 + countPrimes(a,b-1);
	}
	else
		return countPrimes(a,b-1);
}//End of countPrimes()

int main()
{
	int a = 1, b = 20;
	cout << "\nTotal prime numbers between " << a << " and " << b << " is : " << countPrimes(a,b) << "\n";

	return 0;
}//End of main()
