/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/

char * removeSpaces(char *s) {
	int i, j; 
	if (s == "" || s == '\0')
	return '\0';
		i = 0;
		j = 0;
		while (s[i] != '\0')
		{
			if (s[i] != ' ')
			{
				s[j] = s[i];
				j++;
			}
			i++;
		}
		s[j] = '\0';
		return(s);
}