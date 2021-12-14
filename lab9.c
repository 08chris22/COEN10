//Christian Garcia COEN 10L Monday 2:15 PM

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10
#define SIZE 20 

int main (void);
void input (void);
void reverse (void);
void uppercase (void);
void info (void);
void output (void);

char words [MAX][SIZE];
int length [MAX];
int counter = 0;

int main (void)
{
	input();
	reverse();
	uppercase();
	info();
	return 0;
}

void input (void)
{
	int x,i,j,k;
	char word[SIZE];
	printf ("Please enter a string.\n");
	for (i=0;i<10;i++)
	{
		x = scanf("%s", words[i]);
		if (words[i][0] != '\0')
		{
			counter++;
		}
		if (x<1)
		{
			break;
		}
	}
	fflush(stdin);
	for (i=0;i<counter;i++)
	{
		for (j=i+1;j<counter;j++)
		{
			strcpy(word, words[j]);
			if (strcasecmp(words[i], words[j]) > 0)
			{
				for (k=j;k>1;k--)
				{
					strcpy(words[k], words[k-1]);
				}
				strcpy(words[i], word);
			}
		}
	}
	printf("Alphabetical Order:\n");
	output();
	return;
}

void reverse (void)
{
	int i = 0;
	int j = counter - 1;
	char back[SIZE];
	while (i<j)

		strcpy(back, words[i]);
		strcpy(words[i], words[j]);
		strcpy(words[j], back);
		i++;
		j--;
	}
	printf("Reverse:\n");
	output();
	return;
}

void uppercase (void)
{
	char*p;
	int i;
	for (i=0;i<counter;i++)
	{
		p=words[i];
		while(*p != '\0')
		{
			if (islower((int)*p))
			{
				*p=toupper((int)*p);
			}
			p++;
		}
		length[i] = strlen(words[i]);
	}
	printf("Uppercase:\n");
	output();
	return;
}

void info (void)
{
	int shorty = 0;
	int longy = 0;
	int avg = 0;
	int i = 0;
	int notlet[MAX];
	while (i<counter)
	{
		avg += length[i];
		if (!isalpha((int) words[i][0]))
		{
			notlet[i] = 1;
		}
		if (length[i] > length[longy])
		{
			longy = i;
		}
		else if (length[i] < length[shorty])
		{
			shorty = i;
		}
		i++;
	}
	avg /= counter;
	printf("Shortest: %d\n", shorty);
	printf("Longest: %d\n", longy);
	printf("Average Length: %d\n", avg);
	printf("Words that don't start with a letter:\n");
	for (i=0;i<10;i++)
	{
		if (notlet[i] == 1)
		{
			printf("%s\n", words[i]);
		}
	}
	return;
}

void output (void)
{
        int i;
        for (i=0; i < counter; i++)
        {
                if (words[i][0] != '\0')
                {
                        printf("%s\n", words[i]);        
                }
        }
	return;
}
