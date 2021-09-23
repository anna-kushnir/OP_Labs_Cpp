#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	double a, b;    //катети
	double S;       //площа
	cout << "Введiть довжину першого катета: "; cin >> a;
	cout << "Введiть довжину другого катета: "; cin >> b;
	S = a * b / 2;
	cout << "\n";
	cout << "Площа прямокутного трикутника: ";
	cout << S;
	cout << "\n";
	system("pause");
}