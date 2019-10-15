int main()
{
	setlocale(LC_ALL, "Russian");
	int array[100], last = 0;
	for (int i = 0; i < 100; i++) {
		cin >> array[i];
	}

	int count = 0;
	for (int i = 0; i < 100 && count < 10; i++){
		if (array[i] > 15) {
			cout << "значение: " << array[i] << "\tпозиция: " << i << "\n";
			count++;
		}
	}

	if (count == 0) {
		cout << "Таких значений нет";
	}
	else if (count < 10) {
		cout << "Таких значений больше нет";
	}
}
