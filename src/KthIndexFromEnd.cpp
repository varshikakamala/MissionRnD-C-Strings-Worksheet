/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	int i = 0;
	if (str == "" || str == '\0')
	return '\0';
	else
	{
		while (str[i] != '\0') i++;
		if(K < 0 || K>=i)
			return '\0';
		else if (K == 0) return str[i-1];
		else if (K == (i - 1)) return str[0];
		else if (K == (i - 1) / 2)   return str[i / 2];
		else			return str[K];
	}
}