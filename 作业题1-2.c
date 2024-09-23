#include<stdio.h>
int main()
{
	int sum = 0;
	int price = 0;
	int input = 0;
	scanf_s("%d", &price);
	do
	{
		getchar();
		scanf_s("%d", &input);
		sum += input;
		if(price<=sum)
			printf("%d", sum - price);
	} while ( 0 < price && (input == 1 || input == 2 || input == 5));
	printf("Invalid input(error!):The input must be 1,2or5");
	return 0;
}