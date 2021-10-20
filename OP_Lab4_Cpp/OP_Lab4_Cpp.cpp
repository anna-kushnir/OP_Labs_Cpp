#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	unsigned long n;        // кiлькiсть членiв послiдовностi
	float a;                // n-ий член послiдовностi
	float Sum;              // результат
	cout << "¬ведiть значенн€ n: "; cin >> n;
	a = 2;
	Sum = a;
	for (int i = 2; i <= n; i = i + 1) {
		a = (a * a) / (a + 3);
		Sum = Sum + a;
	}
	cout << "—ума n членiв послiдовностi: ";
	cout << Sum << endl;
	system("pause");
}