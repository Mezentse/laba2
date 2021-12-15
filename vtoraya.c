#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void pyzur(char* num, int size, clock_t* s, clock_t* e) 
{
	*s = clock();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--)
		{
			if (num[j - 1] > num[j])
			{
				char temp = num[j - 1];
				num[j - 1] = num[j];
				num[j] = temp;
			}
		}
	}
	*e = clock();
}

void vstavka(char* num, int size, clock_t* s, clock_t* e)
{
	char newElement;
	int location;
	*s = clock();
	for (int i = 1; i < size; i++)
	{
		newElement = num[i];
		location = i - 1;
		while (location >= 0 && num[location] > newElement)
		{
			num[location + 1] = num[location];
			location = location - 1;
		}
		num[location + 1] = newElement;
	}
	*e = clock();
}

void quickSort(char* data, int first, int last)
{
	char temp = 0;
	if (first < last)
	{
		int left = first, right = last, middle = data[(left + right) / 2];
		do
		{
			while (data[left] < middle)
			{
				left++;
			}
			while (data[right] > middle)
			{
				right--;
			}
			if (left <= right)
			{
				temp = data[left];
				data[left] = data[right];
				data[right] = temp;
				left++;
				right--;
			}
		} while (left < right);
		quickSort(data, first, right);
		quickSort(data, left, last);
	}
}

int main()
{
	clock_t start, end;
	
	int n = 0;
	long long b = 0;
	int c = 0;
	int p = 0;

	
	srand(time(NULL));

	while (p != 4)
	{
		FILE* fin;
		fin = fopen("input.txt", "r");
		fscanf_s(fin, "%d", &n);
		char* a = NULL;
		a = (char*)malloc(n * sizeof(char));
		
		for (int i = 0; i < n; i++)
		{
			fscanf_s(fin, "%d", &a[i]);
		}

		printf("\nEnter sorting method\n1-Pyzur\n2-Vstavka\n3-QuickSort\n4-Exit\nInput:");
		scanf("%d", &p);
		printf("\n");

		if (p == 1) {
			pyzur(a, n, &start, &end);
			printf("Pyzur\n");
			for (int i = 0; i < n; i++)
				printf("a[%d] = %d\n", i, a[i]);
			printf("start = %lf end = %lf vremya = %lf\n", (double)start, (double)end, (double)(end - start) / CLOCKS_PER_SEC);
			printf("______________________________________\n");
		}

		if (p == 2) {
			printf("Vstavka\n");
			vstavka(a, n, &start, &end);
			for (int i = 0; i < n; i++)
				printf("a[%d] = %d\n", i, a[i]);
			printf("start = %lf end = %lf vremya = %lf\n", (double)start, (double)end, (double)(end - start) / CLOCKS_PER_SEC);
			printf("______________________________________\n");
		}

		if (p == 3) {
			printf("QuickSort\n");
			start = clock();
			quickSort(a, 0, n - 1);
			end = clock();
			for (int i = 0; i < n; i++)
				printf("a[%d] = %d\n", i, a[i]);
			printf("start = %lf end = %lf vremya = %lf\n", (double)start, (double)end, (double)(end - start) / CLOCKS_PER_SEC);
			printf("______________________________________\n");
		}

		if (p == 4) break;
	}

	return 0;
}