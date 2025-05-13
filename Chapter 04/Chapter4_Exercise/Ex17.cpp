//Ex17.cpp : Write a program for converting an infix expression to prefix and evaluating that prefix expression.
//It will evaluate only single digit numbers.

#include<iostream>
#include<stack>
#include<string>
using namespace std;

string infixToPrefix(string infix);
long int evaluatePrefix(string prefix);
int precedence(char symbol);
int power(int b, int a);

int power(int b, int a)
{
	int result=1;

	for(int i=1; i<=a; i++)
		result *= b;

	return result;
}//End of power()

long int evaluatePrefix(string prefix)
{
	long int a,b,temp,result;
	int i;
	stack<int> st;
	
	for(i=prefix.length()-1; i>=0; i--)
	{
		if(prefix[i]<='9' && prefix[i]>='0')
			st.push(prefix[i]-48);
		else
		{
			b = st.top();
			st.pop();
			a = st.top();
			st.pop();
			switch(prefix[i])
			{
			case '+':
				temp = b+a; break;
			case '-':
				temp = b-a; break;
			case '*':
				temp = b*a; break;
			case '/':
				temp = b/a; break;
			case '%':
				temp = b%a; break;
			case '^':
				temp = power(b,a);
			}
			st.push(temp);
		}//End of else
	}//End of for

	result = st.top();
	st.pop();

	return result;
}//End of evaluatePrefix()

//This function returns the precedence of the operator
int precedence(char symbol )
{
	switch(symbol)
	{
	case ')':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default : 
		 return 0;
	}//End of switch
}//End of precedence()

string infixToPrefix(string infix)
{
	string prefix = "";
	stack<char> st;
	int i,j,n;
	char next ;
	char symbol;	
	char temp;
	n = infix.length();
	
	for(i=n-1; i>=0; i--)
	{
		symbol=infix[i];
		switch(symbol)
		{
		case ')':
			st.push(symbol);
			break;
		case '(':
			while((next=st.top()) != ')')
			{
				prefix += next;
				st.pop();
			}
			st.pop();
			break;
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case '^':
			while(!st.empty() &&  precedence(st.top()) > precedence(symbol) )
			{
				prefix += st.top();
				st.pop();
			}
			st.push(symbol);
			break;
		default: //if an operand comes
			    prefix += symbol;
		}//End of switch
	}//End of for

	while(!st.empty())
	{
		prefix += st.top();
		st.pop();
	}
	
	for(i=0,j=prefix.length()-1;i<j;i++,j--)
	{
		temp = prefix[i];
		prefix[i] = prefix[j];
		prefix[j] = temp;
	}

	return prefix;
}//End of infixToPrefix()

int main()
{
	string infix = "7+5*3^2/(9-2^2)+6*4";
	string prefix;

	cout << "Infix expression is : " << infix << "\n";

	prefix = infixToPrefix(infix);

	cout << "Prefix expression is :\n";
	cout << prefix << "\n";

	cout << "Value of expression is :\n";
	cout << evaluatePrefix(prefix) << "\n";

	return 0;
}//End of main()
