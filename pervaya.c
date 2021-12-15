#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
	int n = 0;
	int k = 0;
	
	FILE* lol;
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	
	lol = fopen("C:/Users/mezen/source/repos/laba2.2/laba2.2/input.txt", "w");
	
	printf_s("Введите количество чисел:");
	scanf_s("%d", &n);
	fprintf(lol, "%d\n", n);

	printf_s("Как вы хотите ввести числа?\nНажмите 1, если хотите ввести сами\nНажмите 2, если хотите получить случайные числа\nВаш выбор:");
	scanf_s("%d", &k);
	
	if (k == 1)
	{
		for (int i = 0; i < n; i++)
		{
			int a = 0;
			scanf_s("%d", &a);
			fprintf(lol, "%d\n", a);
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			char a = -128 + rand() % (256);
			fprintf(lol, "%d\n", a);
		}
	}

	return 0;
}