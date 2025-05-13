//Ex44.cpp : Write a function to print all possible permutations of a string.

#include<iostream>
#include<string>
using namespace std;

void swap(char *a, char *b)
{
	char temp = *a;  *a=*b; *b=temp;
}//End of swap

void Permutation1(char str[], char* currentptr)
{
	char *ptr;

	if(*(currentptr + 1) == '\0')
	   cout << str << "\t";
	else
	{
		for(ptr=currentptr; *ptr!='\0'; ptr++)
		{
			swap(ptr,currentptr);
			Permutation1(str, currentptr+1);
			swap(ptr,currentptr);
		}
	}
}//End of Permutation1()

void Permutation2(char str[], int startIndex, int lastIndex)
{
	int i;
	if(startIndex == lastIndex)
	{
		for(i=0; i<=lastIndex; i++)
			cout << str[i];
		cout << "\t";
	}
	else
	for(i=startIndex; i<=lastIndex; i++)
	{
		swap(&str[startIndex], &str[i]);
		Permutation2(str,startIndex+1,lastIndex);
		swap(&str[startIndex], &str[i]);
	}
}//End of Permutation2()

int main()
{
	char str[10] = "abc";

	Permutation1(str,str);
	cout << "\n\n";
	Permutation2(str,0,strlen(str)-1);
	cout << "\n";

	return 0;
}//End of main()
