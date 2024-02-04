/*
create rock paper and scissor game
player1 - rock
player 2 (computer) - scissor --> player 1 gets 1 point

rock vs scissor - rock wins
paper vs scissor - scissor wins
paper vs rock - rock wins 
write a c program to allow user to play this game three times with the computer. log the scroes 
of the computer and the player then display the name of the winner at the end 
note: you have to display the name of player during the game take users name as an input from the 
user
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int generate_random_number(int n)
{
	srand(time(NULL));//srand takes input from the user and is defined inside the #include<stdlib.h>
	return rand()%n;
}

int greater(char char1,char char2)
{
//	for rock,paper and scissor returns 1 if c1>c2 and 0 otherwise if c1==c2 it will return -1
	
//	if (char1 == char2);
//	{
//		return -1;
//	}
	if((char1 == 'R') && (char2 == 'S'))
	{
		return 1;
	}
	else if((char2 == 'R') && (char1 == 'S'))
	{
		return 0;
	}
	
	if((char1 == 'P') && (char2 == 'R'))
	{
		return 1;
	}
	else if((char2 == 'P') && (char1 == 'R'))
	{
		return 0;
	}
	
	if((char1 == 'S') && (char2 == 'P'))
	{
		return 1;
	}
	else if((char2 == 'S') && (char1 == 'P'))
	{
		return 0;
	}
	if (char1 == char2);
	{
		return -1;
	}

}

int main()
{
	int i;
	int playerscore = 0, computerscore = 0,temp;
	char playerchar, computerchar;
	char dict[]={'R','P','S'};
	printf("				***** Welcome to the Rock, Paper & Scissor game.*****\n\n");
	for(i=0;i<3;i++)
	{
//	take player 1 input 
	printf("Choose 1 for Rock, 2 for Paper and 3 for Scissor\n\n");
	printf("Player 1's Turn = ");
	scanf("%d",&temp);
	getchar();
	playerchar = dict[temp-1];
	printf("Player 1's Choose = %c\n\n",playerchar);
	
//	generate computer input
//	printf("Choose 1 for Rock, 2 for Paper and 3 for Scissor\n\n");
//	printf("Computer's turn = ");
//	printf("%d\n",generate_random_number(temp));
	temp = generate_random_number(3) + 1;
	computerchar = dict[temp-1];
	printf("Computer's Choose = %c\n\n",computerchar);
	
//	compare these scores
	if(greater(computerchar, playerchar) == 1)
	{
		computerscore += 1;
		printf("Computer's got it!\n\n");
	}
	else if(greater(computerchar, playerchar) == -1)
	{
		computerscore += 1;
		playerscore += 1;
		printf("It's Draw.\n\n");
	}
	else 
	{
		playerscore += 1;
		printf("You got it!\n\n");
	}
	
	printf("Player 1's Score = %d\n",playerscore);
	printf("Computer's Score = %d\n\n",computerscore);
	
	}
	if(playerscore > computerscore)
	{
		printf("Hurray! Player 1 Wins the game.\n");
	}
	else if(playerscore < computerscore)
	{
		printf("Hurray! Computer Wins the game.\n");
	}
	else
	{
		printf("It's Draw.\n");
	}
//	printf("The random number between 0 to 5 is %d\n",generate_random_number(2));
	return 0;
}
