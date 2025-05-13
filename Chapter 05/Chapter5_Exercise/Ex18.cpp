//Ex18.cpp : Write a recursive function to display a line of text in reverse order.

#include<iostream>
#include<string>
using namespace std;

void reverseLine(string line, int i)
{
	if(i == 1)
	{
		cout << line[0] << "\n";
		return;
	}
	else
	{
		cout << line[i-1];
		reverseLine(line, i-1);
	}

}//End of reverseLine()

int main()
{
	string line = "There is a man in a hut";

	cout << "Line is : " << line << "\n";

	cout << "Reversed line is : ";
	reverseLine(line,line.length());

	return 0;
}//End of main()

