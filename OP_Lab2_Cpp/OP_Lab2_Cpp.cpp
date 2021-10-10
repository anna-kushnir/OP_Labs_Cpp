#include <iostream>

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
		if (a1 / b1 == a2 / b2 && a2 / b2 == a3 / b3) cout << "Вектори a i b колiнеарнi" << endl;     //Головна умова колінеарності векторів
		else cout << "Вектори a i b не є колiнеарними" << endl;
	}
	else {
		if ((a1 == 0 && a2 == 0 && a3 == 0) || (b1 == 0 && b2 == 0 && b3 == 0) || (a1 == b1 && a2 == b2 && a3 == b3)) 
			 cout << "Вектори a i b колiнеарнi" << endl;                                              //Нульовий вектор колінеарний будь-якому іншому вектору
                                                                                                      //Два рівні вектори колінеарні
		else cout << "Помилка. Введiть iншi координати вектора b." << endl;
	}
	system("pause");
}