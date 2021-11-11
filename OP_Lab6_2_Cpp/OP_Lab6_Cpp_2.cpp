#include <iostream>
using namespace std;

long double Comb(long n, long k)
{
	long double C = 1;
	long i, j, m;
	for (i = 1; i <= n; i++)
		C = C * i;
	for (j = 1; j <= k; j++)
		C = C / j;
	for (m = 1; m <= n - k; m++)
		C = C / m;
	return C;
}

void triangle(long n)
{
	long double C;
	for (long i = 0; i <= n; i++)
	{
		long k = i;
		for (long j = 0; j <= k; j++)
		{
			if (j == 0 || i == j)
				C = 1;
			else
				C = Comb(i, j);
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