#include<stdio.h>
#include<conio.h>
#include<string.h>

#define space ' '

void Input(int*, int*, char*);
char* Mygets(char*, int);

int main()
{

	int number[5] = { 0 };//初始定义每个槽的物品数量都是零
	int price[5] = { 0 };

	char category[5] = { '0' };
	Input(number, price, category);//part1 end!now there is cargo in the machine

	//part2 initialize the requirement

	int channel_cargo, price_cargo, input, sum = 0;
	int number_cargo = 0;
	price_cargo = 0;
	char cargo;
	char String[64];
	char* temp[] = { "0" };
start:;


	while (Mygets(String, sizeof(String)) != NULL)
	{

		sscanf_s(String, "%c %d %d", &cargo, 1, &channel_cargo, &number_cargo);

		if (strncmp(String, "END", 3) == 0)
		{
			printf("Alright,let's pay the bill:\n");
			break;
		}
		else {
			if (('A' <= cargo && cargo <= 'Z') && (0 <= channel_cargo && channel_cargo < 6))
			{
				if (0 <= number_cargo && number_cargo <= number[channel_cargo - 1])
				{
					price_cargo += number_cargo * price[channel_cargo - 1];
					number[channel_cargo - 1] -= number_cargo;

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

				case '2': {
					printf("Enter new requirement:\n");
					while (getchar() != '\n')
						;
					goto start;
				}


				case '3':goto help; break;
				case '4':
				{
					for (int k = 0; k < 5; k++)
					{
						if (number[k] != 0 && number[k] != 1)
						{
							printf("There are %d %c in No.%d channel.Price:$%d/bottle\n", number[k], category[k], (k + 1), price[k]);
							printf("Input your requirement:\n");
						}
						else if (number[k] == 0)
						{
							printf("There is nothing left in No.%d channel.\n", (k + 1));
							printf("Change the channel to have another drink:\n");
						}
						else
						{
							printf("There is only one left in the No.%d channel:$%d/bottle\n", k + 1);
							printf("Enter to buy:");
						}
					}

				}break;
				default:break;
					while (getchar() != '\n')
						continue;
				}

			}
		}skip_error:
		;

	}
	do
	{
		printf("PAY:\n");
		if (price_cargo <= sum)
		{
			printf("Here is the charge:%d\n", sum - price_cargo);
			sum = 0;//reset
			price_cargo = 0;
			printf("reset the requirement:\n");
			while (getchar() != '\n')
				continue;
			goto start;
		}
		else {
			scanf_s("%d", &input);
			sum += input;
		}



	} while (0 < price_cargo && (input == 1 || input == 2 || input == 5) && sum != 0);
	if (sum == 0)
		goto skip_error;
	printf("Invalid input(error!):The input must be 1,2or5\n");
	printf("BYE\n");









	return 0;
help:
	printf("\n\n\n%50cHELP\n\n\n", space);
	printf("1.每种货物均由一个大写英文字母表示（如A,B,C...X,Y,Z）\n2、假定这个售货机只有5个通道用来摆放货物，每个通道只能放一种货物，且每个通道最多放入50个货物；不同的通道可以放相同种类的货物\n3、假定每种货物的单价均在10元以下，且均为整数\n");

pause:
	printf("Bye.");

}

void Input(int* num, int* pri, char* cat)
{
	int tem2;//2:channel 
	int tem3;//3:number
	int tem4;//4:price
	char tem1;//1:category
	char string[64] = "0";

start:;

	do
	{
		tem1 = '0';
		tem2 = 0;
		tem3 = 0;
		tem4 = 0;
		char* array[5] = { "0" };
		unsigned int test;
		int* temp[5] = { {0} };


		if (Mygets(string, sizeof(string)) != NULL)
		{
			test = strncmp(string, "END", 3);

			if (test == 0)
			{

				printf("OK Choose whatever you want;\n");


				break;
			}

			else//不是end
			{
				if (sscanf_s(string, "%c %d %d %d", &tem1, sizeof(tem1), &tem2, &tem3, &tem4) == 4)
				{

					cat[tem2 - 1] = tem1;//将字母存入category
					num[tem2 - 1] += tem3;
					pri[tem2 - 1] = tem4;


				}
				else
				{

					printf("ERROR:Invalid input:\n");
					printf("RE-INPUT:\n");

					goto start;




				}

			}
		}

		else
		{
			printf("Overfloat or illegal input:\n");
			printf("Restart inputing:\n");
			goto start;//一般不会出现这种情况（字符串输入一般可以被录入）
		}

	} while (num[tem2 - 1] <= 50 && ('A' <= tem1 && tem1 <= 'Z') && (0 < tem2 && tem2 < 6) && (0 <= tem3 && tem3 < 50) && (0 < tem4 && tem4 < 10));
}


char* Mygets(char* str, int n)
{
	char* result;
	int i = 0;
	result = fgets(str, n, stdin);

	if (result)
	{
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (str[i] == '\n')
			str[i] = '\0';
		else
			while (getchar() != '\n')
				continue;
	}

	return result;
}