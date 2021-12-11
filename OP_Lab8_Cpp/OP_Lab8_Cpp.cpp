#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

typedef float Matrix[10][10];
Matrix A, B;
int n;
void input(Matrix);
void output(Matrix);
void creation(Matrix);

int main()
{
	cout << "Enter the dimension (size) of the matrix: ";
	cin >> n;
	input(A);
	cout << "The matrix A:" << endl;
	output(A);
	creation(A);
	cout << "The matrix B:" << endl;
	output(B);
	system("pause");
}

void input(Matrix matr)
{
	srand(time(NULL));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matr[i][j] = rand() % 50 + 1;
}

void output(Matrix matr)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(7) << setprecision(3) << matr[i][j];
		printf("\n");
	}
	printf("\n");
}

void creation(Matrix matr)
{
	float Sum;
	int k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			Sum = 0;
			k = 0;
			if (j != 0) 
			{
				Sum += A[i][j - 1];
				k++;
			}
			if (j != n - 1) 
			{
				Sum += A[i][j + 1];
				k++;
			}
			if (i != 0) 
			{
				Sum += A[i - 1][j];
				k++;
			}
			if (i != n - 1) 
			{
				Sum += A[i + 1][j];
				k++;
			}
			B[i][j] = Sum / k;
		}
}