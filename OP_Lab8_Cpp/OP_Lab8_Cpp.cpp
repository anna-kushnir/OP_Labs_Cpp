#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

float** input(int, int);
void output(float**, int);
float** creation(float**, int);
void deleting(float**, int);

int main()
{
	int n;
	cout << "Enter the dimension (size) of the matrix: ";
	cin >> n;
	float** A, ** B;
	int maxA;
	cout << "Enter the maximum possible value of an element from matrix A: ";
	cin >> maxA;
	cout << endl;
	A = input(n, maxA);
	cout << "The matrix A:" << endl;
	output(A, n);
	B = creation(A, n);
	cout << "The matrix B:" << endl;
	output(B, n);
	deleting(A, n);
	deleting(B, n);
	system("pause");
	return 0;
}

float** input(int m, int maxRand)
{
	float** matr = new float* [m];
	for (int i = 0; i < m; i++)
		matr[i] = new float[m];
	srand(time(NULL));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			matr[i][j] = rand() % maxRand + 1;
	return matr;
}

void output(float** matr, int m)
{
	float M;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			M = matr[i][j];
			cout << setw(8) << setprecision((M < 10) ? 2 : 
				(M < 100) ? 3 : (M < 1000) ? 4 : 6) << M;
		}
		printf("\n");
	}
	printf("\n");
}

float** creation(float** matr, int m)
{
	float** matr2 = new float* [m];
	for (int i = 0; i < m; i++)
		matr2[i] = new float[m];
	float Sum;
	int k;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++) {
			Sum = 0;
			k = 0;
			if (j != 0) {
				Sum += matr[i][j - 1];
				k++;
			}
			if (j != m - 1) {
				Sum += matr[i][j + 1];
				k++;
			}
			if (i != 0) {
				Sum += matr[i - 1][j];
				k++;
			}
			if (i != m - 1) {
				Sum += matr[i + 1][j];
				k++;
			}
			matr2[i][j] = Sum / k;
		}
	return matr2;
}

void deleting(float** matr, int m)
{
	for (int i = 0; i < m; i++)
		delete[] matr[i];
	delete[] matr;
}