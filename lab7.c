//Christian Garcia Lab 7 COEN 10L Monday 2:15

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void scheduler(void);
void cancel(void);
void list(void);
void letter(void);

int counter=0;
int schedule[5] = {0,0,0,0,0};
int i;
int j;
int times;
char lett;
char name[20];
char appoint[5][20];

int main()
{
        int answer;

        while (1)
        {
		printf ("Welcome to Stinky Pet Spa Inc.\n");
                printf ("Appointment  Waiting List\n Menu\n 1 - Schedule\n 2 - Cancel\n 3 - List\n 4 - Letter\n 9 - Quit\n");
                scanf ("%d", &answer);          
                switch (answer)
                {
                        case 1:
                                scheduler();
                                break;
                        case 2:
                                cancel();
                                break;
                        case 3:
                                list();
                                break;
			case 4:
				letter();
				break;
                        case 9:
                                return 0;
                        default:
                                printf ("Bad Input!\n");
                }

        }

}

void scheduler (void)
{
        if (counter == 5)
        {       
                printf ("There are no availble slots at the moment. Try again tomorrow.\n");
		return;
        }
	else
	{
		printf("What is your name?\n");
                scanf("%s", &name);
		strcpy(appoint[counter], name);
		counter++;
		printf("Your appointment is scheduled for %s at %dPM.\n", name, counter);
		return;
	}		
}

void cancel (void)
{
	if (counter == 0)
	{
		printf("There are no appointments scheduled.\n");
		return;
	}

	else
	{
		printf("What name is your appointmentnt under?\n");
		scanf("%s", &name);
		for (i = 0; i < 5; i++)
		{
			if (strcmp(appoint[i], name) == 0)
			{
				appoint[i][0] = '\0';
				printf("%s has canceelled their appointment at %dPM.\n", name, i+1);
				counter--;
				for (j = i; j < counter; j++)
				{
					strcpy(appoint[j], appoint[j+1]);
					printf("The appointment for %s has been changed from %dPM to %dPM.\n", appoint[j], j+2, j+1);
				}
			}
			
			else if (i == 5)
			{
				printf("There is no appointment under that name.\n");
			}
		}
	}
	return;
}

void list (void)
{
        for (i = 0; i < counter; i++)
	{
		printf("%dPM - %s\n", i + 1, appoint[i]);
	}
	for (i = counter; i  < 5; i++)
	{
		printf("%dPM - Free\n", i + 1);
	}
	return;
}

void letter (void)
{
	if (counter == 0)
	{
                printf("There are no appointments scheduled.\n");
		return;
	}
	else
	{
		printf("What is the letter of your appointment?\n\n");
		scanf("%c", &lett);
		for (i = 0; i < 5; i++)
		{
			if(appoint[i][0] == lett)
			{
				printf("%s has an appointment scheduled.\n", appoint[i]);
			}
		}
		return;
	}
}
