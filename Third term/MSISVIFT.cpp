#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int compareValue = 15;
	const int arrayLength = 100;
	const int maxCount = 10;
	const char zeroTextOutput[] = "Таких значений нет";
	const char notFullTextOutput[] = "Таких значений больше нет";
	const char valueTextOutput[] = "значение: ";
	const char valuePositionTextOutput[] = "\tпозиция: ";

	int array[arrayLength];
	int count = 0;

	for (int i = 0; i < arrayLength; i++) {
		cin >> array[i];
	}

	for (int i = 0; i < arrayLength && count < maxCount; i++){
		if (array[i] > compareValue) {
			cout << valueTextOutput << array[i] << valuePositionTextOutput << i << "\n";
			count++;
		}
	}

	if (count == 0) {
		cout << zeroTextOutput;
	}
	else if (count < maxCount) {
		cout << notFullTextOutput;
	}
}
