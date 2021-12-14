//Christian Garcia Lab 6 COEN 10L Monday 2:15

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void scheduler(void);
void cancel(void);
void list(void);

int counter=0;
int schedule[5] = {0,0,0,0,0};
int i;
int times;

int main()
{
        int answer;

        while (1)
        {
		printf ("Welcome to Stinky Pet Spa Inc.\n");
                printf ("Appointment  Waiting List\n Menu\n 1 - Schedule\n 2 - Cancel\n 3 - List\n 9 - Quit\n");       //Creating the menu that the user will see upon starting the program.
                scanf ("%d", &answer);               //Reading the answer that the user inputs.
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
                        case 9:
                                return 0;
                        default:
                                printf ("Bad Input!\n");        //In case the user inputs a value that isn't 1, 2, 3, 9.
                }

        }

}

void scheduler (void)
{
      if (counter == 5)             //If there are no more available appointments the user won't be allowed to schedule one.
        {       
                printf ("There are no availble slots at the moment.\n");
                return;
        }
	for(i = 0; i < 5; i++)
		if (schedule[i]==0)
		{
			schedule[i]++;
			counter++;
			printf("Your appointment is scheduled for %dPM.\n", i + 1);
			return;
		}		
}

void cancel (void)
{
	if (counter == 0)
		printf("There are no appointments.\n");

	else
	{
		printf("What time is your appointment?\n");
		scanf("%d", &times);
		
		for (i=0; i < 5; i++)
		{
			if(schedule[i] == times)
			{
				schedule[i] = 0;
				counter--;
				printf ("Your appiontment for %dPM is cancelled.\n", times);
				return;
			}
		}
	}
}

void list (void)
{
        for(i=0;i<5;i++)
		if(schedule[i] == 0)
			printf("%dPM - Free\n", i+1);
		else
			printf("%dPM - Busy\n", i+1);
	return;
}
