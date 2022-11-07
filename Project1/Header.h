
#pragma once

#include <stdio.h>
#include <malloc.h>
#include <math.h>

char* unification(char* a, char* b);
int ConvertToInt(char* s);
char* ConvertToString(int n);
void GetDlinaOtr();
float GetDlina(int x1, int y1, int x2, int y2);
void GetPerPlosh();
int GetProverka(float a, float b, float c);


int Summa(int a, int b)
{
	int x = a + b;
	printf("Сумма элементов :%d", x);
}

int Difference(int a, int b)
{
	int x = a - b;
	printf("Разность элементов :%d", x);
}

int Product(int a, int b)
{
	int x = a * b;
	printf("Произведение элементов :%d", x);
}

int Quotient(int a, int b)
{
	float x = (float)a / (float)b;
	printf("Частное элементов :%3.2f", x);
}