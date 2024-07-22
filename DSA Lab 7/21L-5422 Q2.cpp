#include <iostream>
using namespace std;

void Print(int row, int col, int** arr) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void Product(int row1, int col1, int** M1, int row2, int col2, int** M2, int** Result) {
	static int rows = 0, cols = 0, k = 0;

	if (rows >= row1)
		return;

	if (cols < col2) {
		if (k < col1) {
			Result[rows][cols] += M1[rows][k] * M2[k][cols];
			k++;

			Product(row1, col1, M1, row2, col2, M2, Result);
		}
		k = 0;
		cols++;
		Product(row1, col1, M1, row2, col2, M2, Result);
	}
	cols = 0;
	rows++;
	Product(row1, col1, M1, row2, col2, M2, Result);
}

void MatMul(const int row1, const int col1, int** Matrix1, int row2, int col2, int** Matrix2) {
	if (row2 != col1) {
		cout << "It is not Possible" << row2 << "&" << col1 << " CASE: NOT EQUAL";
		return;
	}

	int** Result = new int* [row1];
	for (int i = 0; i < row1; i++) {
		Result[i] = new int[col1];
		for (int j = 0; j < col1; j++) {
			Result[i][j] = 0;
		}
	}
	Product(row1, col1, Matrix1, row2, col2, Matrix2, Result);
	cout << "Final Matrix\n";
	Print(row1, col1, Result);
}

int main() {
	int** M1 = 0;
	int** M2 = 0;
	int r1 = 0, c1 = 0, r2 = 0, c2 = 0;
	cout << "Enter Row No for Matrix1: ";
	cin >> r1;
	cout << "Enter Row No for Matrix2: ";
	cin >> r2;

	cout << "Enter COL No for Matrix1: ";
	cin >> c1;
	cout << "Enter COL No for Matrix2: ";
	cin >> c2;

	cout << "Enter Elements of Matrix 1" << endl;
	M1 = new int* [r1];
	for (int i = 0; i < r1; i++) {
		M1[i] = new int[c1];
		for (int j = 0; j < c1; j++) {
			cin >> M1[i][j];
		}
	}


	cout << "Enter Elements of Matrix 2" << endl;
	M2 = new int* [r2];
	for (int i = 0; i < r2; i++) {
		M1[i] = new int[c2];
		for (int j = 0; j < c2; j++) {
			cin >> M2[i][j];
		}
	}


	system("CLS");
	cout << "Matrix1\n";
	Print(r1, c1, M1);
	cout << "\nMatrix2\n";
	Print(r2, c2, M2);

	MatMul(r1, c1, M1, r2, c2, M2);

	return 0;
}