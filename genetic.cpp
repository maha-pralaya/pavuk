// ConsoleApplication8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <ctime>
#include <cmath>
#include <iostream>
using namespace std;

void sortdv(float**);
float fitness(float,float);
bool prov(float**, int*);
void cross(float**);
void mutat(float**);

int main()
{
	int numb, counter=0;
	float **pop = new float*[10];
	srand(time(NULL));
	setlocale(LC_ALL, "RUS");
	for (int i = 0; i < 10; i++)
	{
		pop[i] = new float[2];
		for (int j = 0; j < 2; j++)
		{
			pop[i][j] = ((rand()%30000 - 15000)*0.0001);
			cout << pop[i][j] << " ";
		}
		cout << "\n";
	}

	while (prov(pop,&numb)) 
	{
		sortdv(pop);
		cross(pop);
		mutat(pop);
		counter++;
		if (counter == 1000)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << pop[i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n";
			counter = 0;
		}
	}
	cout << "Решение: x= " << pop[numb][0] << "; y= " << pop[numb][1] << endl;
	system("pause");
}


bool prov(float** arr, int *num)
{
	for (int i = 0; i < 10; i++)
		if (fitness(arr[i][0], arr[i][1]) <= 0.05)
		{
			*num = i;
			return false;
			break;
		}
	return true;
}

float fitness(float x, float y)
{
	float dzdx = 6 * pow(y, 3)*pow(x, 2) + 12 * pow(x, 3);
	float dzdy = 6 * pow(y, 2)*pow(x, 3) + 5;
	return (abs(dzdx) + abs(dzdy));
}

void cross(float** arrcr)
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (rand() % 9 + i >= 9)
			{
				if (rand() % 2 == 0)
					swap(arrcr[i][0], arrcr[j][0]);
				else swap(arrcr[i][1], arrcr[j][1]);
			}
		}
	}
}

void mutat(float** arrmu)
{
	int num;
	sortdv(arrmu);
	if (prov(arrmu, &num))
	{
		for (int i = 0; i < 10; i++)
		{
			if (2*i + rand() % 10 <= 16)
			{
				//if (rand() % 2 == 0)
					arrmu[i][0] = ((rand() % 30000 - 15000)*0.0001);
				//else 
					arrmu[i][1] = ((rand() % 30000 - 15000)*0.0001);
			}
		}
	}
}

void sortdv(float** arrdv)
{
	int ind, l;
	for (int k = 0; k < 9; k++)
	{
		ind = k;
		for (l = 1; l < 10; l++)
		{
			if (fitness(arrdv[l][0], arrdv[l][1]) > fitness(arrdv[k][0], arrdv[k][1]))
				ind = l;
		}
		swap(arrdv[ind][0], arrdv[k][0]);
		swap(arrdv[ind][1], arrdv[k][1]);
	}
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
