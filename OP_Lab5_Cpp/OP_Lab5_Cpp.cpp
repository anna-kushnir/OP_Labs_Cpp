#include <iostream>
using namespace std;

int main()
{
	unsigned long m, n;        //natural numbers m and n
	unsigned long k;           //natural number k (the result)
	unsigned long i;           //the counter
	unsigned long Sum_k;       //the sum of digits of the number k
	cout << "Enter natural number m: "; cin >> m;
	cout << "Enter natural number n: "; cin >> n;
	for (k = 1; k < m; k = k + 1)
	{
		Sum_k = 0;
		i = k;
		while (i > 0)
		{
			Sum_k = Sum_k + i % 10;
			i = i / 10;
		}
		if (Sum_k == n)
			cout << k << endl;
	}
	system("pause");
}