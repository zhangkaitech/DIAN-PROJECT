#include<stdio.h>
#define space ' '
int func(char category, int channel, int price, int number);
int main()
{
	char category;
	int channel, price, number;
	scanf_s("%c %d %d %d", &category, 1, &channel, &price, &number);
	unsigned result = func(category, channel, price, number);
	if (result == 0)
		;
	else
	{
		printf("Error!错误代码:%u", result);
	}
	return 0;
}
int func(char category, int channel, int number, int price)

{
	if ('A' <= category && category <= 'Z' && 1 < channel && channel < 6 )
	{
		if (0 < number && number < 10 && 0 < price && price < 50)
		{
			printf("%d:", channel);
			for (int i = 0; i < price; i++)
			{
				printf("%c", category);
			}
			putchar(space);
			printf("%d", number);
			putchar(space);
			putchar('\n');
			return 0;
		}
		else
			return -1;
	}
	else
		return -1;

}