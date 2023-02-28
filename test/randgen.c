#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	if (argc != 4)
	{
		printf("no, too little or too many arguments\n");		
	}
	
	int lowerbound = atoi(argv[1]);
	int upperbound = atoi(argv[2]);
	int amount = atoi(argv[3]);
	int total_amount = upperbound - lowerbound + 1;
	int numbers[total_amount];	
	
	if (amount > total_amount)
	{
		printf("range is not big enough for requested amount of integers.\n");
		return (0);
	}	
	int current_number = lowerbound;
	for (int i = 0; i < (total_amount); i++)
	{
		numbers[i] = current_number;
		current_number++;
	}	
	
	srand(time(0));
	for (int i = 0; i < (total_amount); i++)
	{	
		int temp = numbers[i];
		int random_index = rand() % total_amount;
	
		numbers[i] = numbers[random_index];
		numbers[random_index] = temp;
	}


	for (int i = 0; i < amount; i++)
	{	
		if (i == amount - 1)
			printf("%d", numbers[i]);
		else
			printf("%d ", numbers[i]);
	
	}
	printf("\n");
sleep(1);
	return (0);
}

