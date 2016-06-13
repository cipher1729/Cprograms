#include <iostream>
#include <conio.h>
using namespace std;

//KMP algorithm

int * makeLPS(char * s, int N)
{
	int * arr = new int[N];
	int i = 0, j = 1;
	arr[0] = 0;
	while (j < N)
	{
		if (s[j] == s[i])
		{
			if (i == 0)
				arr[j] = 1;
			else
				arr[j] = arr[j - 1] + 1;
			j++;
			i++;
		}
		else
		{
			arr[j++] = 0;
			i = 0;
		}
	}
	return arr;
}

int match(char *s, char *patt, int * LPS, int lenS, int lenPatt)
{
	int pos = -1;
	int i = 0, j = 0;
	while (i < lenS && j < lenPatt)
	{
		if (s[i] == patt[j])
		{	
			i++;
			j++;
			if (j == lenPatt)
				pos = i - lenPatt;
		}
		else
		{
			
			if (j!=0)
			j = LPS[j-1];
			i++;
		}
	}
	if (i > lenS)
		return -1;
	else
		return pos;

}

int main()
{
	char patt[] = "BC";
	int N = (sizeof(patt) / sizeof(char))-1;
	int * ret = makeLPS(patt, N);
	char s[] = "DGAAABCFF";

	cout << match(s, patt, ret, sizeof(s) / sizeof(char), N);
	getchar();
}
