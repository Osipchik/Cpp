#include <iostream>
using namespace std;

struct Matrix {
	int columns;
	int rows;
	int** array;
	int value;
	int valueColumn;
	int valueRow;
};

void SetValue(Matrix& matrix, int currentRow, int currentCol, bool max) {
	cin >> matrix.array[currentRow][currentCol];
	if (max ? matrix.value < matrix.array[currentRow][currentCol] : matrix.value > matrix.array[currentRow][currentCol]
		|| matrix.value == -1) {
		matrix.value = matrix.array[currentRow][currentCol];
		matrix.valueRow = currentRow;
		matrix.valueColumn = currentCol;
	}
}

Matrix CreateMatrix(bool findMin, int rows = 0) {
	int row, col;
	if (rows == 0) cin >> row;
	else row = rows;
	cin >> col;
	Matrix matrix = { col, row, new int* [row], -1 };
	for (int i = 0; i < matrix.rows; i++) {
		matrix.array[i] = new int[matrix.columns];
		for (int j = 0; j < col; j++) {
			SetValue(matrix, i, j, findMin);
		}
	}

	return matrix;
}

void SwapValue(Matrix& matrixA, Matrix& matrixB) {
	for (int i = 0; i < matrixA.columns; i++) {
		int rowValue = matrixA.array[matrixA.valueRow][i];
		int colValue = matrixB.array[i][matrixB.valueColumn];
		matrixA.array[matrixA.valueRow][i] = colValue;
		matrixB.array[i][matrixB.valueColumn] = rowValue;
	}
}

void PrintMatrix(Matrix matrix, bool showValueInfo) {
	cout << "\n";
	for (int i = 0; i < matrix.rows; i++) {
		for (int j = 0; j < matrix.columns; j++) {
			cout << matrix.array[i][j] << "  ";
		}
		cout << "\n";
	}

	if (showValueInfo) {
		cout << "value = " << matrix.value << ", positionX = "
			 << matrix.valueColumn << ", positionY = " << matrix.valueRow << "\n";
	}
	cout << "\n";
}

int main()
{
	Matrix matrixA = CreateMatrix(true);
	PrintMatrix(matrixA, true);
	Matrix matrixB = CreateMatrix(false, matrixA.columns);
	PrintMatrix(matrixB, true);
	SwapValue(matrixA, matrixB);
	PrintMatrix(matrixA, false);
	PrintMatrix(matrixB, false);
}
