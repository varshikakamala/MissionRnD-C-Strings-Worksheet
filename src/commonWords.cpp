/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/
#include <stdio.h>
#include <malloc.h>

#define SIZE 31

int len(char *a)
{
	int i, j = 0;
	for (i = 0; *(a + i) != '\0'; i++)
		j++;
	return j;
}
int noWords(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] != ' ')return 1;
	return 0;
}
char** words(char *str, char **arr)
{
	int i, j = 0, k = 0;
	for (i = 0; str[i]!= '\0'; i++)
	{
		if (str[i] == ' ')
		{
			arr[j][k] = '\0';
			k = 0;
			j++;
		}
		else
		{
			arr[j][k] = str[i];
			k++;
		}
	}
	arr[j][k] = '\0';
	return arr;
}
int numwords(char *str)
{
	int i, j = 0, l, k = 0;
	l = len(str);
	for (i = 1; str[i] != '\0'; i++)
	{
		if (str[i] == ' '&& str[i - 1] != ' ')
			j++;
		if (str[i] == ' ')
			k++;
	}
	if (l == k)
		return 0;
	return j + 1;
}
int strcomp(char *str1, char *str2)
{
	int i;
	for (i = 0; str1[i]!= '\0'; i++)
	{
		if (str1[i] != str2[i])
			return 0;
	}
	return 1;
}
char ** commonWords(char *str1, char *str2) {

	if (str1 == NULL || str2 == NULL)
		return NULL;
	if (noWords(str1) == 0 || noWords(str2) == 0)return NULL;
	char **arr1, **arr2;

	int i, w1, w2, j, x, y = 0, d = 0;
	arr1 = (char **)malloc(sizeof(char *) * 20);
	arr1[0] = (char *)malloc(sizeof(char) * 20 * 20);
	for (i = 0; i < 20; i++)
		arr1[i] = (*arr1 + 20 * i);
	arr2 = (char **)malloc(sizeof(char *) * 20);
	arr2[0] = (char *)malloc(sizeof(char) * 20 * 20);
	for (i = 0; i < 20; i++)
		arr2[i] = (*arr2 + 20 * i);

	arr1 = words(str1, arr1);
	arr2 = words(str2, arr2);
	w1 = numwords(str1);
	w2 = numwords(str2);
	if (w1 == 0 || w2 == 0)
		return NULL;
	for (i = 0; i < w1; i++)
	{
		for (j = 0; j < w2; j++)
		{
			if (len(arr1[i]) == len(arr2[j]))
			{
				x = strcomp(arr1[i], arr2[j]);
				if (x == 1)
				{
					y = 0;
					for (y = 0; y < len(arr1[i]); y++)
					{
						arr1[d][y] = arr1[i][y];
					}
					arr1[d][y] = '\0';
					d++;
				}
			}
		}
	}
	if (d == 0)
		return NULL;
	return arr1;
}
