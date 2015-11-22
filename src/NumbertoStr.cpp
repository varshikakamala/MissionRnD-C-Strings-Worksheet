/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
char *string_reverse(char *s, int l)
{
	char temp;
	int i, j;
	j = 0;
	i = l-1;
	while (i >= l/ 2)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		j++;
		i--;
	}
	return s;
}
int int_string(char *s, int num, int aftrpt)
{
	int i = 0;
	while (num!=0)
	{
		s[i] = (num % 10) + '0';
		i++;
		num /= 10;
	}
	while (i < aftrpt)
	{
		s[i] = '0';
		i++;
	}
	string_reverse(s,i);
	s[i] = '\0';
	return i;
}
void number_to_str(float number, char *str, int afterdecimal){
	int i = 0, intgr_part,n;
	float flt_part,number1=number;
	if (number < 0)
	{
		number= number*(-1);
		str[i] = '-';
		i++;
	}
	intgr_part = (int)number;
	flt_part = number - intgr_part;
	i = int_string(str+i,intgr_part, afterdecimal);
	if (afterdecimal != 0)
	{
		if (number1 < 0)
		{
			i++;
			str[i] = '.';
		}
		else       		str[i] = '.';
		n = afterdecimal;
		while (n != 0)
		{
			flt_part = (flt_part * 10);
			n--;
		}
		int_string(str + i + 1, (int)flt_part, afterdecimal);
	}
}