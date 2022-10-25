//Chloe Marton 
//Dr. Steinberg
//COP3223C Section 004
//Large Program 1

#define ROUNDS 3
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void greeting(); // Displays welcome message
int playRound(int round);// Game play
int humanPick();//Gets human input
int computerPick(int choice, int leftover);//Computer picks 
int leftOnTable(int toothpicks, int taken);//Calculates number of toothpicks left 
void winnerAnnouncment(int user);//Determines winner of round 




int main()
{
    greeting();


    for(int x = 0; x < ROUNDS; ++x)
	{
		int result = playRound(x + 1); //calls and starts game 
		
		//determines winner and passes it to winner announcment 
		int user;
			if(result == 1)
			{
				user = 1;
			}
			else
			{
				user = 0;
			}

	
		winnerAnnouncment(user);
	}
	

	

	printf("********************************************************\n");
	printf("Thank you for playing!\n");
	return 0;


}




//greeting 
void greeting()
{
	printf("********************************************************\n");
	printf("Welcome to Toothpick Game!\n");
	printf("Here are the rules.\n");
	printf("There are currently 31 toothpicks on the table.\n");
	printf("You and I will each get a turn to pick either 1, 2, or 3 toothpicks off the table.\n");
	printf("The player that picks the last toothpicks loses the game!\n");
	printf("Ready to play?...Here we go!\n");
	printf("********************************************************\n");
}




//game play 
int playRound(int round)
{
	printf("Welcome to a new round %d!\n", round);
	printf("You may go first!\n");
	
	int toothpicks = 31; //number of toothpicks to start with
	
	int result;
	
	while(toothpicks != 0)
	{
		
		//states toothpicks left  
		printf("There are %d toothpicks left on the table \n", toothpicks);

		//human pick 
		int choice = humanPick();

		//Ensures correct input, gives user a second chance if input is incorrect 
		if (choice >= 4 || choice <= 0)
		{
			printf("Invalid number choice! Try again.\n");
			choice = humanPick();
			if(choice < 4)
				{
					printf("You took %d off the table.\n", choice);
					
				}
		}
		else
		{
			printf("You took %d off the table.\n", choice);
		}
		//-------------------------------------------------------


		//checks if computer won 
		int leftover = toothpicks - choice; 
			if(leftover == 0)
			{
				result = 1;
				return result; 
			}
		
		
		//computer picks 
		int cpick = computerPick(choice, leftover);
		printf("I am taking %d toothpick(s) off the table.\n", cpick);
		
		//adds total taken toothpicks
		int taken = choice + cpick;
		
		//calculates remaining toothpicks 
		toothpicks = leftOnTable(toothpicks, taken);
		printf("there are %d toothpicks remaining\n", toothpicks);
		printf("********************************************************\n");

		//checks if human won 
			if(toothpicks == 0)
			{
				result = 0;
				return result;
			}
		

	}


	return 0;


}




//human pick 
int humanPick()
{
	int choice; 
	printf("How many toothpicks will you take? ");
	scanf("%d", &choice);
	

	return choice; 

}


//left on table 
int leftOnTable(int toothpicks, int taken) 
{
	toothpicks = toothpicks - taken;
	
	
	return toothpicks;
}


//computer pick 
int computerPick(int choice, int leftover)
{
	int cpick;
	
	//if statements to determine how many toothpicks the computer takes
	if(leftover > 4)
	{
		printf("Okay let me think...\n");
		int cpick = 4 - choice;
		return cpick;
	}
	else if(leftover == 4)
	{
		printf("Okay let me think...\n");
		int cpick = leftover - 1;
		return cpick;
	}
	else if(leftover == 3)
	{
		printf("Okay let me think...\n");
		int cpick = leftover - 2;
		return cpick; 
	}
	else if(leftover == 2)
	{
		printf("Okay let me think...\n");
		int cpick = leftover - 1;
		return cpick;
	}
	else
	{ 
		int cpick = 1;
		return cpick;
	}

	
	

	
}

//winner announcment 
void winnerAnnouncment(int user)
{
	if(user == 1)
	{
		printf("********************************************************\n");
		printf("I won! Better luck next time.\n");
		printf("********************************************************\n");

	}
	else
	{
		printf("You won! I let you have this game!\n");
		printf("********************************************************\n");
	}

	
}





