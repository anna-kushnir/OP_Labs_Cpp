#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	unsigned long n;        // �i���i��� ����i� ����i�������i
	float a;                // n-�� ���� ����i�������i
	float Sum;              // ���������
	cout << "����i�� �������� n: "; cin >> n;
	a = 2;
	Sum = a;
	for (int i = 2; i <= n; i = i + 1) {
		a = (a * a) / (a + 3);
		Sum = Sum + a;
	}
	cout << "���� n ����i� ����i�������i: ";
	cout << Sum << endl;
	system("pause");
}