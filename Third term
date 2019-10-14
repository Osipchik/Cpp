#include <iostream>
using namespace std;

struct Matrix {
	int xCount;
	int yCount;
	int** array;
	char arrayName;
	int value;
	int positionX;
	int positionY;
};

void SetValue(Matrix& matrix, int currentY, int currentX, bool max) {
	if (max ? matrix.value < matrix.array[currentY][currentX] : matrix.value > matrix.array[currentY][currentX]
		|| matrix.value == -1) {
		matrix.value = matrix.array[currentY][currentX];
		matrix.positionY = currentY;
		matrix.positionX = currentX;
	}
}

void ReadRowAndCol(int& row, int& col, int rows, char arrayName) {
	cout << "array" << arrayName << ":\n";
	if (rows == 0) cin >> row;
	else {
		cout << rows << "\n";
		row = rows;
	}
	cin >> col;
}

Matrix CreateMatrix(char arrayName, bool findMin, int rows = 0) {
	int row, col;
	ReadRowAndCol(row, col, rows, arrayName);
	
	Matrix matrix = { col, row, new int* [row], arrayName, -1 };
	for (int i = 0; i < row; i++) {
		matrix.array[i] = new int[col];
		for (int j = 0; j < col; j++) {
			matrix.array[i][j] = rand();
			SetValue(matrix, i, j, findMin);
		}
	}

	return matrix;
}

void SwapValue(Matrix& matrixA, Matrix& matrixB) {
	for (int i = 0; i < matrixA.xCount; i++) {
		int rowValue = matrixA.array[matrixA.positionY][i];
		int colValue = matrixB.array[i][matrixB.positionX];
		matrixA.array[matrixA.positionY][i] = colValue;
		matrixB.array[i][matrixB.positionX] = rowValue;
	}
}

void PrintMatrix(Matrix matrix, bool showValueInfo) {
	cout << "\nArray " << matrix.arrayName << ":\n";
	for (int i = 0; i < matrix.yCount; i++) {
		for (int j = 0; j < matrix.xCount; j++) {
			cout << matrix.array[i][j] << "  ";
		}
		cout << "\n";
	}

	if (showValueInfo) {
		cout << "value = " << matrix.value << ", positionX = "
			 << matrix.positionX << ", positionY = " << matrix.positionY << "\n";
	}
}

int main()
{
	Matrix matrixA = CreateMatrix('A', true);
	PrintMatrix(matrixA, true);
	Matrix matrixB = CreateMatrix('B', false, matrixA.xCount);
	PrintMatrix(matrixB, true);
	SwapValue(matrixA, matrixB);
	PrintMatrix(matrixA, false);
	PrintMatrix(matrixB, false);
}
