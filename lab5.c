//Christian Garcia COEN 10L Monday 2:15PM

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main ()

        {
        int num1;             //Declaring the different variables I will need.
        int num2;
        int guess;
	int i;
	int ans;
        int score=0;

        srand((int) time(NULL));

        for(i=0;i<10;i++)          //Creating the ten different tests.
        {

                num1 = rand() % 13;
                num2 = rand() % 13;         //Randomizing the 2 different numbers.

                printf("What is %d * %d?\n",num1, num2);    //Asking the user the question.
                scanf("%d", &guess);
		ans = num1 * num2;

                        if( num1 * num2 == guess)        //Analyzing whether the user's answer is correct.
                        {
                                score += 10;               //Changing the score
                                printf("Good Job!\n");
                        }
                        else
                        {
                                printf("Sorry not right, the correct answer is %d!\n",ans);
                        }
        }

        printf("You got %d%\n", score);       //Telling the user what they got.

        return 0;
        }
