//Ex20.cpp : Write a program to convert postfix expression to prefix.

#include<iostream>
#include<stack>
#include<string>
using namespace std;

string postfixToPrefix(string postfix)
{
	stack<string> st;
	string operand1, operand2;
	char symbol;
	string temp;
	string strin;

	for(int i=0; i<postfix.length(); i++)
	{
		symbol = postfix[i];
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
			strin = temp;
			strin = strin + operand2;
			strin = strin + operand1;
			st.push(strin);
			break;
		default: //if an operand comes
			    st.push(temp);
		}//End of switch
	}//End of for

	return st.top();

}//End of postfixToPrefix()

int main()
{
	string postfix = "ABC*-DE-F*G/H/+";

	cout << "Postfix expression is : " << postfix << "\n";

	cout << "Prefix expression is :\n";
	cout << postfixToPrefix(postfix) << "\n";

	return 0;
}//End of main()


