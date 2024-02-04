#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int generate_random_number(int n)
{
	srand(time(NULL));
	return rand()%n;
}

int greater(char char1,char char2)
{
	if((char1 == 'S') && (char2 == 'W'))
	{
		return 1;
	}
	else if((char2 == 'S') && (char1 == 'W'))
	{
		return 0;
	}
	if((char1 == 'G') && (char2 == 'S'))
	{
		return 1;
	}
	else if((char2 == 'G') && (char1 == 'S'))
	{
		return 0;
	}
	if((char1 == 'W') && (char2 == 'G'))
	{
		return 1;
	}
	else if((char2 == 'W') && (char1 == 'G'))
	{
		return 0;
	}
	if(char1 == char2)
	{
		return -1;
	}
}

int main()
{
	int i;
	int playerscore = 0, computerscore = 0, temp;
	char playerchar,computerchar;
	char dict[] = {'S','W','G'};
	printf("				*****Welcome to Snake, Water & Gun game*****\n\n");
	
	for(i=0;i<3;i++)
	{
		//take player 1 input
		printf("Choose 1 for snake, 2 for water and 3 for gun\n\n");
		printf("Player's 1 turn = ");
		scanf("%d",&temp);
		playerchar = dict[temp-1];
		printf("Player's 1 choose = %c\n",playerchar);
		
		//take computer input
		temp = generate_random_number(3) + 1;
		computerchar = dict[temp-1];
		printf("Computer's choose = %c\n\n",computerchar);
		
		//compare these scores
		if(greater(computerchar,playerchar) == 1)
		{
			computerscore += 1;
			printf("Computer's got it\n\n");
		}
		else if(greater(computerchar,playerchar) == -1)
		{
			computerscore += 1;
			playerscore += 1;
			printf("It's Draw\n\n");
		}
		else 
		{
			playerscore += 1;
			printf("Player's got it\n\n");
		}
		printf("Player's 1 score = %d\n",playerscore);
		printf("Computer's score = %d\n\n",computerscore);
	}
	
	if(playerscore > computerscore)
	{
		printf("Hurray! Player'1 wins the game.\n");
	}
	else if(playerscore < computerscore)
	{
		printf("Hurray! Computer's wins the game.\n");
	}
	else
	{
		printf("It's Draw.\n");
	}
	
	return 0;
}
