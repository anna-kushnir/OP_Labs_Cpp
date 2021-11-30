/* Задана послідовність із k цілих чисел. Перевірити, чи утворюють вони
геометричну прогресію. Якщо так, то визначити знаменник цієї прогресії; 
у противному випадку знайти середнє арифметичне першого і останнього 
елементів послідовності. Замінити отриманим значенням усі непарні 
елементи послідовності. */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

const int k = 10;
int A[k];
void input_a(int[]);
void output_a(int[]);
bool check(int[]);
void change(int);
void find_q(int[]);
void replace(int[]);

int main()
{
	input_a(A);
	cout << "Array: ";
	output_a(A);
	int R = check(A);
	change(R);
	system("pause");
}

void input_a(int arr[])
{
	srand(time(NULL));
	for (int i = 0; i < k; i++)
	{
		arr[i] = rand() % 50 - 9;
	}
}

void output_a(int arr[])
{
	for (int i = 0; i < k; i++)
		printf("%3d", arr[i]);
	printf("\n");
}

bool check(int arr[])
{
	bool R = true;
	for (int i = 1; i < k; i++)
	{
		if (arr[i] == 0 || arr[i-1]==0 || arr[i+1]==0)
		{
			R = false;
			break;
		}
		if (arr[i] * arr[i] != arr[i - 1] * arr[i + 1])
		{
			R = false;
			break;
		}
	}
	return R;
}

void change(int R)
{
	if (R)
	{
		cout << endl << "This is a geometric progression" << endl;
		find_q(A);
	}
	else
	{
		cout << endl << "This is not a geometric progression" << endl;
		replace(A);
	}
}

void find_q(int arr[])
{
	float q = float(arr[1] / arr[0]);
	cout << "Denominator of geometric progression q: " << q << endl;
}

void replace(int arr[])
{
	float am = float((arr[0] + arr[k - 1]))/2;
	cout << "Arithmetic mean of the first and last: " << am << endl;
	for (int i = 0; i < k; i++)
	{
		if (arr[i] % 2 == 1 || arr[i] % 2 == -1)
			arr[i] = float(am);
	}
	cout << "New Array: " << endl;
	output_a(arr);
}