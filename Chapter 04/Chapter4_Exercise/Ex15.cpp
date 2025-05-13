//Ex15.cpp : Write a program to convert a decimal number to binary using a stack.

#include<iostream>
#include<stack>
using namespace std;

long int decimalToBinary(int num)
{
	stack<int> st;
	int rem;

	while(num!=0)
	{
		rem = num%2;
		st.push(rem);
		num/=2;
	}

	int result = 0;
	while(!st.empty())
	{
		result = result*10 + st.top();
		st.pop();
	}

	return result;
}//End of decimalToBinary()

int main()
{
	int num = 10;

	cout << "Decimal Number : " << num << ", Binary is " << decimalToBinary(num) << "\n";

	return 0;
}//End of main()
