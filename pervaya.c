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
	
	printf_s("������� ���������� �����:");
	scanf_s("%d", &n);
	fprintf(lol, "%d\n", n);

	printf_s("��� �� ������ ������ �����?\n������� 1, ���� ������ ������ ����\n������� 2, ���� ������ �������� ��������� �����\n��� �����:");
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