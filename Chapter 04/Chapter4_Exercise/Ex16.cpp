//Ex16.cpp : Write a program to print all the prime factors of a number in descending order using a stack.

#include<iostream>
#include<stack>
using namespace std;

void primeFactors(int num)
{
	stack<int> st;

	for(int i=2; num!=1; i++)
	{
		while(num%i == 0)
		{
			st.push(i);	
			num = num/i;
		}
	}

	while(!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";

}//End of primeFactors()

int main()
{
	int num = 60;

	cout << "Prime factors of " << num << " are :\n";
	primeFactors(num);

	return 0;
}//End of main()
