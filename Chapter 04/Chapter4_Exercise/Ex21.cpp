//Ex21.cpp : Write a program to convert prefix expression to postfix.

#include<iostream>
#include<stack>
#include<string>
using namespace std;

string prefixToPostfix(string prefix)
{
	stack<string> st;
	string operand1, operand2;
	char symbol;
	string temp;
	string strin;

	for(int i=prefix.length()-1; i>=0; i--)
	{
		symbol = prefix[i];
		temp = symbol;

		switch(symbol)
		{
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			operand1 = st.top();
			st.pop();
			operand2 = st.top();
			st.pop();
			strin = operand1;
			strin = strin + operand2;
			strin = strin + temp;
			st.push(strin);
			break;
		default: //if an operand comes
			    st.push(temp);
		}//End of switch

	}//End of for

	return st.top();
}//End of prefixToPostfix()

int main()
{
	string prefix = "+-+A/BC*DEF";

	cout << "Prefix expression is : " << prefix << "\n";

	cout << "Postfix expression is :\n";
	cout << prefixToPostfix(prefix) << "\n";

	return 0;
}//End of main()
