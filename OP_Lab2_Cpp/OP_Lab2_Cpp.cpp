﻿#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	double a1, a2, a3;		//координати вектора a
	double b1, b2, b3;		//координати вектора b
	cout << "Введiть координати вектора a (x;y;z): "; 
	cin >> a1; cin >> a2; cin >> a3;
	cout << "Введiть координати вектора b (x;y;z): ";
	cin >> b1; cin >> b2; cin >> b3;
	if (b1 != 0 && b2 != 0 && b3 != 0) {
		if (a1 / b1 == a2 / b2 && a2 / b2 == a3 / b3) cout << "Вектори a i b колiнеарнi" << endl;
		else cout << "Вектори a i b не є колiнеарними" << endl;
	}
	else cout << "Помилка. Введiть вектор b, всi координати якого не дорiвнюють нулю" << endl;
	system("pause");
}