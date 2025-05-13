//Ex32.cpp : Write recursive functions to find values of floor of log N base 2 and floor of log N base b.

#include<iostream>
using namespace std;

int log2(int num) 
{ 
      if(num==1) 
           return 0;
      return 1 + log2(num/2);
}//End of log2()

int logN(int num,int base) 
{ 
      if(num<base) 
           return 0;
     return 1 + logN(num/base,base);
}//End of logN()

int main()
{
	int n = 8;
	cout << "Floor of log " << n << " base " << 2 << " = " << log2(n) << "\n";

	n = 81;
	int b = 3;
	cout << "Floor of log " << n << " base " << b << " = " << logN(n,b) << "\n";

	return 0;
}//End of main()
