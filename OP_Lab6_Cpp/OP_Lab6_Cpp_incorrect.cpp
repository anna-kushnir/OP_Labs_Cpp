#include <iostream>
using namespace std;

long double factorial(long i)
{
	if (i == 0) return 1;
	else
	{
		long double f = 1;
		while (i >= 1)
		{
			f *= i;
			i--;
		}
		return f;
	}
}

void triangle(long n)
{
	long long C;
	for (long i = 0; i <= n; i++)
	{
		long k = i;
		for (long j = 0; j <= k; j++)
		{
			C = factorial(i) / (factorial(j) * factorial(i - j));
			cout << C << " ";
		}
		cout << endl;
	}
}

int main()
{
	long n;
	cout << "Enter the value of n: "; cin >> n;
	cout << endl;
	cout << "The Pascal's triangle:" << endl;
	triangle(n);
	system("pause");
}