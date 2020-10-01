#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable : 4996);

char bin_num1[9], bin_num2[9];

void read_file(void);
void add(void);
void trans(void);
void write_file(void);

int main(void)
{
	read_file(); //функция считывания этих 2ух чисел из файла === удержывая Ctrl+лкм переходим к коду
	add();
	trans();
	write_file;
	printf("%s\n", bin_num1);
	return 0;
}

void read_file(void)
{
	FILE *in = fopen("input.txt","r");
	if (in == NULL)
	{
		printf("Error: file \"input.txt\" did not open\n");
		exit(EXIT_FAILURE);
	}

	fgets(bin_num1, 17, in);
	fgetc(in);
	fgets(bin_num2, 17, in);

	if (fclose(in) != 0)
	{
		printf("Error: file \"input.txt\" did not close\n");
		exit(EXIT_FAILURE);
	}
	else
		return;
}

void add(void)
{
	for (int i = 7; i >= 0; i--)
	{
		if (bin_num1[i] == '0')
		{
			if (bin_num2[i] == '0')
				bin_num1[i] = '0';
			else
				bin_num1[i] = '1';
		}
		else
		{
			if (bin_num2[i] == '0')
				bin_num1[i] = '1';
			else
			{
				bin_num1[i] = '0';
				for (int j = i; j >= 1; j--)
				{
					if (bin_num1[j - 1] == '1')
						bin_num1[j - 1] = '0';
					else
					{
						bin_num1[j - 1] = '1';
						break;
					}
				}
			}
		}
	}
}

void trans(void)
{
	if (bin_num1[0] = '1')
	{
		if (bin_num1[7] == '1')
			bin_num1[7] = 0;
		else
		{
			bin_num1[7] = '1';
			for (int j = 7; j >= 2; j--)
			{
				if (bin_num1[j - 1] == '0')
					bin_num1[j - 1] = '1';
				else
				{
					bin_num1[j - 1] = '0';
					break;
				}
			}
		}
	}
}

void write_file(void)
{
	FILE *out = fopen("output.txt", "w+");
	if (out == NULL)
	{
		printf("Error: file \"input.txt\" did not open\n");
		exit(EXIT_FAILURE);
	}

	fputs(bin_num1, out);

	if (fclose(out) != 0)
	{
		printf("Error: file \"input.txt\" did not close\n");
		exit(EXIT_FAILURE);
	}
	else
	{
	}
}