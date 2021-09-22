#include <iostream>

using namespace std;

int main() {
	double a, b;    //катети
	double S;       //площа
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	S = (a * b) / 2;
	cout << "S = ";
	cout << S;
	cout << "\n";
	system("pause");
}