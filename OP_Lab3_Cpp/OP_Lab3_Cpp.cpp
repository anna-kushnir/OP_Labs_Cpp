#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	float x;             // початкове дане
	unsigned long n;     // лічильник
	float a;             // n-ий член послідовності
	float Sum;           // результат
	cout << "Введiть значення x: "; cin >> x;
	n = 1;
	a = x / 2;
	Sum = a;
	while (n < 11)
	{
		n = n + 1;
		a = (a * x) / (2 * n * (2 * n - 1));
		Sum = Sum + a;
	}
	while (abs(a) >= 0.00001)
	{
		n = n + 1;
		a = (a * x) / (2 * n * (2 * n - 1));
		Sum = Sum + a;
	}
	cout << "Сума k членiв послiдовностi, якi задовольняють умову: " << endl;
	printf("Sum = %.5f\n", Sum);
	system("pause");
}
