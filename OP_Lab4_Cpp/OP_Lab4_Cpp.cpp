#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	long n;        // ������� ����� �����������
	float a;       // n-�� ���� �����������
	float Sum;     // ���������
	cout << "������ �������� n: "; cin >> n;
	a = 2;
	Sum = a;
	for (int i = 2; i <= n; i=i+1) {
		a = (a * a) / (a + 3);
		Sum = Sum + a;
	}
	cout << "���� n ����� �����������: ";
	cout << Sum << endl;
	system("pause");
}