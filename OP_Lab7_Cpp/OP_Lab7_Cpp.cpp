/* Задана послідовність із k цілих чисел. Перевірити, чи утворюють вони
геометричну прогресію. Якщо так, то визначити знаменник цієї прогресії; 
у противному випадку знайти середнє арифметичне першого і останнього 
елементів послідовності. Замінити отриманим значенням усі непарні 
елементи послідовності. */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
using namespace std;

void input_a(float *p, const int m)
{
	srand(time(NULL));
	for (int i = 0; i < m; i++)
	{
		*p = rand() % 50 - 9;
		p++;
	}
}

void output_a(float *p, const int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << float(*p) << "  ";
		p++;
	}
	printf("\n");
}

bool check(float arr[], const int m)
{
	bool R = true;
	for (int i = 1; i < m - 1; i++)
	{
		if (arr[i] == 0 || arr[i - 1] == 0 || arr[i + 1] == 0 ||
			arr[i] * arr[i] != arr[i - 1] * arr[i + 1])
		{
			R = false;
			break;
		}
	}
	return R;
}

float find_q(float arr[])
{
	float q = arr[1] / arr[0];
	return q;
}

void replace(float arr[], const int n)
{
	float am = (arr[0] + arr[n - 1]) / 2;
	cout << "Arithmetic mean of the first and last: " << am << endl;
	for (int i = 0; i < n; i++)
	{
		if (int(arr[i]) % 2 == 1 || int(arr[i]) % 2 == -1)
		{
			arr[i] = am;
		}
	}
}

int main()
{
	const int k = 10;
	float A[k];
	input_a(A, k);
	cout << "Array: " << endl;
	output_a(A, k);
	bool R = check(A, k);
	if (R)
	{
		cout << endl << "This is a geometric progression" << endl;
		float q = find_q(A);
		cout << "Denominator of geometric progression q: " << q << endl;
	}
	else
	{
		cout << endl << "This is not a geometric progression" << endl;
		replace(A, k);
		cout << "New Array: " << endl;
		output_a(A, k);
	}
	cout << endl;
	system("pause");
}