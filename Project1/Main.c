#include "Header.h"

#define kvadrat(a) pow(a,2)

//#define ax1 6
//#define ay1 5
//#define ax2 8
//#define ay2 3
//#define ax3 4
//#define ay3 6

#define GetDlina(yx1, yy1, yx2, yy2) sqrt(kvadrat(yx2 - yx1) + kvadrat(yy2 - yy1))

//#define a1 4
//#define b1 7
//#define c1 6

int main(void)
{
	system("chcp 1251>nul");

	int n;
	while (1)
	{
		printf("\nВведите номер задания: \nЗадание 1 - Сумма чисел\nЗадание 2 - Разность чисел\nЗадание 3 - Произведение чисел\nЗадание 4 - Частное чисел\nЗадание 5 - Объединение двух строк\n Задание 6 - Преобразовать число в строку и строку в число\nЗадание 7 - Нахождение длины отрезка по координатам двух точек\n Задание 8 - Проверка существования треугольника и нахождение периметра и площади\n9 - Завершить работу программы\n");
		scanf_s("%d", &n);
		switch (n)
		{
		case (1):
			system("cls");
			int s1, s2;
			printf("Введите первое слагаемое: ");
			scanf_s("%d", &s1);
			printf("Введите второе слагаемое: ");
			scanf_s("%d", &s2);
			Summa(s1, s2);
			break;

		case (2):
			system("cls");
			int y, v;
			printf("Введите уменьшаемое: ");
			scanf_s("%d", &y);
			printf("Введите вычитаемое: ");
			scanf_s("%d", &v);
			Difference(y, v);
			break;

		case (3):
			system("cls");
			int m1, m2;
			printf("Введите первый множитель: ");
			scanf_s("%d", &m1);
			printf("Введите второй множитель: ");
			scanf_s("%d", &m2);
			Product(m1, m2);
			break;

		case (4):
			system("cls");
			int a, b;
			printf("Введите делимое: ");
			scanf_s("%d", &a);
			printf("Введите делитель: ");
			scanf_s("%d", &b);
			Quotient(a, b);
			break;

		case (5):
			break;

		case (6):
			system("cls");
			char* s = "159243";
			int num = ConvertToInt(s);
			printf("Число: %d", num);
			char* str = ConvertToString(num);
			printf("\nСтрока: %s\n", str);
			system("pause");

			break;

		case (7):
			system("cls");
			GetDlinaOtr();
			system("pause");

			break;

		case (8):
			system("cls");
			GetPerPlosh();
			system("pause");
			break;

		case (9):
			break;



		default:

			printf("Было выбрано задание не из тех, что существуют! Повторите ввод!");
		}
	}
}

char* unification(char* a, char* b)
{
	int l1 = 0, l2 = 0;
	while (a[l1] != '\0')
	{
		l1++;
	}
	while (a[l2] != '\0')
	{
		l2++;
	}
	char* c = calloc(l1 + l2, sizeof(char));
	for (int i = 0; i < l1; i++) {
		c[i] = a[i];
	}
	for (int i = 0; i < l2; i++) {
		c[i + l1] = b[i];
	}
	c[l1 + l2] = '\0';
	return c;
}

int ConvertToInt(char* s)
{
	int number = 0;
	int sign = 0; 
	int i = 0;
	if (s[0] == '-')
	{
		sign = 1;
		i++;
	}
	while (s[i] != '\0')
	{
		number = number + (s[i] & 0x0F);
		number = number * 10;
		i++;
	}
	number = number / 10;
	if (sign == 1)
	{
		number = -number;
	}
	return(number);
}


char* ConvertToString(int a)
{
	int i = 0, k, l1 = 0;
	int sign = 0; 
	if (a < 0)
	{
		sign = 1;
		a = -a;
		l1++;
	}
	int n1 = a;
	while (a > 0) 
	{
		a = a / 10;
		l1++;
	}
	char* str1 = calloc(l1, sizeof(char));
	a = n1;
	while (a > 0)
	{
		k = a % 10;
		a = a / 10;
		str1[i] = k | 0x30;
		i++;
	}
	if (sign == 1)
	{
		str1[i] = '-';
		i++;
	}
	i--;
	char* str2 = calloc(l1, sizeof(char));
	while (i >= 0) {
		str2[a] = str1[i];
		i--; a++;
	}
	str2[a] = '\0';
	return(str2);
}

void GetDlinaOtr() 
{
	int x1, y1, x2, y2;
	printf("Есть две точки A(x1; y1) и B(x2; y2)\n");
	printf("Введите x1: ");
	scanf_s("%d", &x1);
	printf("Введите y1: ");
	scanf_s("%d", &y1);
	printf("Введите x2: ");
	scanf_s("%d", &x2);
	printf("Введите y2: ");
	scanf_s("%d", &y2);
	float dl = GetDlina(x1, y1, x2, y2);
	printf("Длина отрезка: %f\n", dl);
}


void GetPerPlosh() 
{
	int x1, y1, x2, y2, x3, y3; 
	printf("Введите точки треугольника A(x1; y1), B(x2; y2), C(x3, y3)\n");
	printf("Введите x1: ");
	scanf_s("%d", &x1);
	printf("Введите y1: ");
	scanf_s("%d", &y1);
	printf("Введите x2: ");
	scanf_s("%d", &x2);
	printf("Введите y2: ");
	scanf_s("%d", &y2);
	printf("Введите x3: ");
	scanf_s("%d", &x3);
	printf("Введите y3: ");
	scanf_s("%d", &y3);
	float a = GetDlina(x1, y1, x2, y2);
	float b = GetDlina(x1, y1, x3, y3);
	float c = GetDlina(x2, y2, x3, y3);
	int prov = GetProverka(a, b, c);
	if (prov == 0)
	{
		printf("Введённые точки не образуют треугольник!\n");
	}
	else
	{
		float P = a + b + c;
		printf("Периметр треугольника равен: %f\n", P);
		float p = P / 2;
		float S = sqrt(p * (p - a) * (p - b) * (p - c));
		printf("Площадь треугольника равна: %f\n", S);
	}
}

int GetProverka(float a, float b, float c) {
	if (a >= b + c)
	{
		return 0;
	}
	else if (b >= a + c)
	{
		return 0;
	}
	else if (c >= a + b)
	{
		return 0;
	}
	else {
		return 1;
	}
}





