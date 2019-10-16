#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	const int compareValue = 15;
	const int arrayLength = 100;
	const int zeroValue = 0;
	const int maxCount = 10;
	const char zeroTextOutput[] = "Таких значений нет";
	const char notFullTextOutput[] = "Таких значений больше нет";
	const char valueTextOutput[] = "значение: ";
	const char valuePositionTextOutput[] = "\tпозиция: ";


	int array[arrayLength];
	for (int i = zeroValue; i < arrayLength; i++) {
		cin >> array[i];
	}

	int count = zeroValue;
	for (int i = zeroValue; i < arrayLength && count < maxCount; i++){
		if (array[i] > compareValue) {
			cout << valueTextOutput << array[i] << valuePositionTextOutput << i << "\n";
			count++;
		}
	}

	if (count == zeroValue) {
		cout << zeroTextOutput;
	}
	else if (count < maxCount) {
		cout << notFullTextOutput;
	}
}
