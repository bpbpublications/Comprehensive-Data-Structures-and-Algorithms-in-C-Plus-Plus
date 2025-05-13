//Ex34.cpp : Write a recursive function to compute Ackermann’s function A(m,n).

#include<iostream>
using namespace std;

int A(int m, int n)
{
	if(m==0) 
		return n+1;
	else if(n==0)
		return A(m-1,1);
	else
		return A(m-1,A(m,n-1)); 
}//End of A()

int main()
{
	int m = 3, n = 2;

	cout << "A(" << m << "," << n << ") = " << A(m,n) << "\n";

	return 0;
}//End of main()
