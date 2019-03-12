
#include <tchar.h>
#include <conio.h>
#include <iostream.h>

int main()
{
	int rows, cols;
	cout << " input size of matrix: rows, cols \n";
	cin >> rows >> cols;
	int **arr = new int *[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];

	int **B = new int *[rows];
	for (int i = 0; i < rows; i++)
		B[i] = new int[cols];

	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			arr[i][j] = rand() % 20;

	 for (int i = 0; i < rows; i++)
	 {
		 for (int j = 0; j < cols; j++)
			 cout << arr[i][j] << '\t';
		 cout << endl;
	 }
	 cout << endl;


	 for (int bi = 0; bi < rows; bi++)
	 {
		 for (int bj = 0, max = 0; bj < cols; bj++)
		 {
			 max = arr[bi][bj];
			 for (int i = bi, t = 0; i >= 0; i--, t++)
			 {
				 for (int j = 0; j < (bj + t); j++)
				 {
					 if (j == cols) break;
					 if (max < arr[i][j]) max = arr[i][j];
				 }
			 }
			 for (int i = bi, t = 0; i < rows; i++, t++)
			 {
				 for (int j = 0; j < (bj - t); j++)
				 {
					 if (j == cols) break;
					 if (max < arr[i][j]) max = arr[i][j];
				 }
			 }
			 B[bi][bj] = max;
		 }
	 }

	 cout << endl;

	 for (int i = 0; i < rows; i++)
	 {
		 for (int j = 0; j < cols; j++)
			 cout << B[i][j] << '\t';
		 cout << endl;
	 }

	 for (int i = 0; i < rows; i++)
		 delete[] arr[i];
	 delete[] arr;

	 for (int i = 0; i < rows; i++)
		 delete[] B[i];
	 delete[] B;
         getch();
         return 0;
}


