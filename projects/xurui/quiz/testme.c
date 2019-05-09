#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	int n = rand() % 95 + 32; // from ' ' to '~'; the probability to get a wanted character is 1/95
    char c = (char) n;
	return c;
}

char *inputString()
{
    // TODO: rewrite this function
    char str[6];
	char str2[] = "rest";
    int i;
    for(i = 0; i < 5; i++)
	{
       int n = rand() % 4; // the probability to get a wanted character is 1/4; the probability to get the string "reset" is (1/4)**5
       char c = str2[n]; 
       str[i] = c;
    }
    str[5] = '\0';
	return str;
}

void testme()
{
    int tcCount = 0;
    char *s;
    char c;
	int state = 0;
	while (1)
	{
		tcCount++;
		c = inputChar();
		s = inputString();
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' '&& state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e' && s[2] == 's' && s[3] == 'e' && s[4] == 't' && s[5] == '\0' && state == 9)
		{
			printf("error\n");
			break;
			//exit(200);
		}
	}
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
