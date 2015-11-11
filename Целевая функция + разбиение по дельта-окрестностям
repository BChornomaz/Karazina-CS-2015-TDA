#include "stdafx.h"
#include <iostream>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	cout << "write down the dimension of vector" << endl;
	long int n;
	cin >> n;
	cout << "write down the numper of vectors" << endl;
	long int N;
	cin >> N;

	long float *mas_with_consistence;
	mas_with_consistence = new long float[N];// Массив для плотностей
	long int *mas_with_numbers;
	mas_with_numbers = new long int[N];// Массив для номеров точек или просто точек
	
	int **POINTS = new int*[N];
	for (int i = 0; i < N; i++)
	{
		POINTS[i] = new int[n];
	}
	// Массив, где i-тая строка заполнена координатами i-той точки
	for (int i = 0; i < N; i++)
	{
		cout << " Bring in coordinates of " << i+1 << "-vecotr" << endl;
		for (int j = 0; j < n; j++)
		{
			cin >> POINTS[i][j];
		}
	}
	float distance = 0;
	float sum = 0;
	float e,c_e;
	cout << "Bring in e and c_e" << endl << "e = ";
	cin >> e;
	cout << "c_e = ";
	cin >> c_e;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (j != i)
			{
				for (int k = 0; k < n; k++)
				{
					distance += (POINTS[i][k] - POINTS[j][k])*(POINTS[i][k] - POINTS[j][k]);
				}
			}
			sum += exp(((-1)* distance) / e);
		}
		mas_with_consistence[i] = c_e*sum;// Высчитывается плотноть i-той точки и засылается в массив
		distance = 0;
		sum = 0;
	}

	/* for (int i = 0; i < N; i++)
	{
		cout << mas_with_consistence[i] << "  ";
	}*/
	

	for (int i = 0; i < N; i++)
	{
		mas_with_numbers[i] = i + 1; // Заполняем наш массив номерами точек
	}
	float smth; // временная переменная для обмена элементов местами
	int smth_1;
	// Сортировка массива пузырьком
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (mas_with_consistence[j] > mas_with_consistence[j + 1])
			{
				smth = mas_with_consistence[j];
				smth_1 = mas_with_numbers[j];
				mas_with_consistence[j] = mas_with_consistence[j + 1];
				mas_with_numbers[j] = mas_with_numbers[j + 1];
				mas_with_consistence[j + 1] = smth;
				mas_with_numbers[j + 1] = smth_1;
			}
		}
	}

	// Получили отсортированный массив с плотностями и так же отсортированный массив с номерами точек
	int k;
	float alpha;
	cout << "bring in the value of k - the number of areas - and the value of alpha - coeficient, 1 < alpha < 2" << endl;
	cout << "k = ";
	cin >> k;
	cout << endl;
	cout << "alpha = ";
	cin >> alpha;
	cout << endl;
	float E; //  шаг
	float d; // радиус разброса
	E = (mas_with_consistence[N - 1] - mas_with_consistence[0]) / (k - 1);
	d = E / alpha;
	cout << "E = " << E << endl;
	cout << "d = " << d << endl;
	int amount = 0;

	float step = 0;
	int g = 0;
	int**MASS = new int*[k];
	int*M_L = new int[k];
	for (int j = 0; j < k+1; j++)
	{

		amount = 0;
		for (int i = 0; i < N; i++)
		{
			if (mas_with_consistence[i] <= (step + d) && mas_with_consistence[i] >= (step - d))  amount++;
		}
		MASS[g] = new int[amount];
		M_L[g] = amount;

		amount = 0;
		for (int i = 0; i < N; i++)
		{
			if (mas_with_consistence[i] <= (step + d) && mas_with_consistence[i] >= (step - d))
			{
				MASS[g][amount] = i;
				amount++;
			}
		}


		g++;
		step = step + E;
	}

	for (int i = 0; i < k+1; i++)
	{
		for (int j = 0; j < M_L[i]; j++)
		{
			cout << mas_with_numbers[MASS[i][j]] << "  ";
		}
		cout << endl;
	}

	int y;
	cin >> y;
	
	return 0;
}
