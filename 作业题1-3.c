#include<stdio.h>
#define space ' '

int func(char category, int channel, int price, int number);
int main()
{

	char category;//Part 1
	int channel, price, number;
start:
	scanf_s("%c %d %d %d", &category, 1, &channel, &price, &number);
	unsigned result = func(category, channel, price, number);
	if (result == 0)
		;
	else
	{
		printf("Error!错误代码:%u", result);
	}//To place the cargo then check the efffectiveness

	//Part 2(To initialize the requirements)
	int channel_cargo, number_cargo, sum, price_cargo, input;
	char cargo;
	while (getchar() != '\n')
		continue;
	while (scanf_s("%c %d %d", &cargo, 1, &channel_cargo, &number_cargo))
	{
		if (('A' <= cargo && cargo <= 'Z') && (category == cargo) && (0 < channel_cargo && channel_cargo < 6) && channel == channel_cargo)
		{
			if (0 < number_cargo && number_cargo <= number)
			{
				price_cargo = number_cargo * price;
				sum = 0;
				do
				{
					if (price_cargo <= sum)
					{
						printf("Here is the charge:%d\n", sum - price_cargo);
						number -= number_cargo;
						sum = 0;//reset
						printf("reset the requirement:\n");
						while (getchar() != '\n')
							continue;
					}
					else {
						scanf_s("%d", &input);
						sum += input;
					}



				} while (0 < price_cargo && (input == 1 || input == 2 || input == 5) && sum != 0);
				if (sum == 0)
					goto skip_error;
				printf("Invalid input(error!):The input must be 1,2or5\n");
				printf("re-input the requirment and insert coins or notes:\n");


			}
			else
			{
				printf("No enough cargo!Reset:\n");
				while (getchar() != '\n');
				continue;
				goto skip_error;
			}
		}
		else
		{
			printf("Invalid input:can not find the cargo you want(or there is an error when choosing channel)\n(Do you want to quit?)\n");
			printf("Choose 1,2,3or4 and enter:\n");
			printf(" 1.Press a to quit%-5c 2.Press space to restart\n", space);
			printf(" 3.Press c to get help%-1c 4.To check the remaining cargo\n", space);
			while (getchar() != '\n')
				continue;
			char get = getchar();
			switch (get) {
			case '1':goto pause; break;
			{
			case '2': goto start; printf("Enter new requirement:\n"); break;
			}
			case '3':goto help; break;
			case '4': 
				printf("There is %d %c in the %d channel.Each of them worths %d\nChange your option:\n", number, category, channel, price);break;
			default:break;
				while (getchar() != '\n')
					continue;
			}

		}skip_error:
		;

	}

pause:
	printf("Bye.");


help:
	printf("\n\n\n%50cHELP\n\n\n", space);
	printf("1.每种货物均由一个大写英文字母表示（如A,B,C...X,Y,Z）\n2、假定这个售货机只有5个通道用来摆放货物，每个通道只能放一种货物，且每个通道最多放入50个货物；不同的通道可以放相同种类的货物\n3、假定每种货物的单价均在10元以下，且均为整数\n");
	printf("在该Level只考虑一种货物一个通道的情况\n");


	return 0;
}
int func(char category, int channel, int number, int price)

{
	if ('A' <= category && category <= 'Z' && 1 < channel && channel < 6)
	{
		if (0 < number && number < 10 && 0 < price && price < 50)
		{
			;
			return 0;
		}
		else
			return -1;
	}
	else
		return -1;

}


