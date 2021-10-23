#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	unsigned long n;        // the number of members of the sequence
	float a;                // nth member of the sequence
	float Sum;              // result
	cout << "Enter the value of n: "; cin >> n;
	a = 2;
	Sum = a;
	for (int i = 2; i <= n; i++) {
		a = (a * a) / (a + 3);
		Sum = Sum + a;
	}
	cout << "The sum of n members of the sequence: ";
	cout << Sum << endl;
	system("pause");
}