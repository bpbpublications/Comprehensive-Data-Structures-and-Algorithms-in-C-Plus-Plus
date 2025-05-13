//Ex33.cpp : Write a recursive function to find the Binomial coefficient C(n,k).

#include<iostream>
using namespace std;

int BC(int n, int k)
{
	if(k==0 || k==n)
		return 1;

	return BC(n-1,k-1) + BC(n-1,k);
}//End of BC()

int main()
{
	int n = 3, k = 2;

	cout << "C(" << n << "," << k << ") = " << BC(n,k) << "\n";

	return 0;
}//End of main()
