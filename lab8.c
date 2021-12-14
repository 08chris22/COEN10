//Christian Garcia Lab 8 COEN 10L Monday 2:15

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void scheduler(void);
void cancel(void);
void list(void);
void letter(void);
void groupsize(void);

int counter=0;
int schedule[5] = {0,0,0,0,0};
int times;
char lett;
char name[20];
char appoint[5][20];
char numbers[5][20];
char phonenum[20];
int sizes[5];
int group;
int i, j;

int main()
{       
        int answer;
        
        while (1)
        {       
                printf ("Welcome to Stinky Pet Spa Inc.\n");
                printf ("Appointment  Waiting List\n Menu\n 1 - Schedule\n 2 - Cancel\n 3 - List\n 4 - Letter\n 5 - Group Size\n 9 - Quit\n");
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
                        case 5: 
                                groupsize();
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
                printf ("Sorry, there are no availble slots at the moment. Try again tomorrow.\n");
                return;
        }
        else
        {
                i = counter - 1;
                printf("What is the name for your appointment?\n");
                scanf("%s", &name);
                if (counter != 0)
                {
                        for (i=0; i < counter; i++)
                        {
                                if (strcmp(name, appoint[i]) == 0)
                                {
                                        printf("Sorry this name is already taken, please choose a new name.\n");
                                        scanf("%s", &name);
                                        i = 0;
                                }

                                else
                                {
                                        i++;
                                }
			}
                }
                strcpy(appoint[counter], name);
                printf("What is the phone number for your appointment?\n");
                scanf("%s", &phonenum);
                strcpy(numbers[counter], phonenum);
                printf("How many pets will we be making an appointment for?\n");
                scanf("%d", &group);
                sizes[counter] = group;
                counter++;
                printf("%s your appointment is scheduled for %dPM for %d pets. Contact Number - %s.\n", name, counter, group, phonenum);
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
				numbers[i][0] = '\0';
				sizes[1] = 0;
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
	if (counter == 0)
	{
		printf("There are currently no appointments scheduled.\n");
		return;
	}
	else
	{
	        for (i = 0; i < counter; i++)
	        {
	                printf("%dPM -Name- %s -# of Pets- %d -Phone Number- %s\n", i + 1, appoint[i], sizes[i], numbers[i]);
	        }
	        for (i = counter; i  < 5; i++)
	        {
	                printf("%dPM - Free\n", i + 1);
	        }
		return;
	}
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
                                printf("%s has an appointment scheduled at %dPM.\n", appoint[i], i + 1);
                        }
                }
                return;
        }
}

void groupsize(void)
{
        if (counter == 0)
        {
                printf("There are no appointments scheduled.\n");
                return;
        }
        else
        {
                printf("What is your group size for your appointment?\n");
                scanf("%d", &group);
                for (i = 0; i < 5; i++)
                {
			if(group == sizes[i])
			{
				printf("%s has an appointment at %dPM for %d pets.\n", appoint[i], i + 1, group);
			}
		}
		return;
	}
}
