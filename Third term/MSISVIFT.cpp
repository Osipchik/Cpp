#include <iostream>
using namespace std;

int main()
{
		setlocale(LC_ALL, "Russian");
	const int compareValue = 15, arrayLength = 100, maxCount = 10, minCount = 0;
	const char messageEmpty[] = "Таких значений нет", messageAll[] = "Таких значений больше нет";

	int array[arrayLength], count = i = 0;

	for (; i < arrayLength; i++) {
		cin >> array[i];
	}

	for (i = 0; i < arrayLength && count < maxCount; i++){
		if (array[i] > compareValue) {
			cout << array[i] << "\t" << i << "\n";
			count++;
		}
	}

	if (count == minCount) {
		cout << "Таких значений нет";
	}
	else if (count < maxCount) {
		cout << "Таких значений больше нет";
	}
}
