
#include <iostream>
#include <string>
#include <clocale>
#include <windows.h>
using namespace std;

bool chek(const string data);
float total_coast(const int system_year, const int year, const int distance, const int engine_capacity);

int main()
{
	setlocale(LC_CTYPE, "rus");
	cout.unsetf(ios::scientific);

	SYSTEMTIME systemtime;
	GetSystemTime(&systemtime);
	const int systemYear = systemtime.wYear;
	
	string data;
	int year, distance, engine_capacity;
	float coast;

	while (true)
	{
		if (data != "")
		{
			system("cls");
			cout << "Ошибка, повтоите ввод\n";
		}
		cout << "стоимость: ";
		cin >> data;
		if(chek(data))
		{
			coast = stof(data);
			if(coast < 0) continue;
			system("cls");
			data = "";
			break;
		}
	}
	
	while (true)
	{
		if(data != "")
		{
			system("cls");
			cout << "Ошибка, повтоите ввод\n";
		}
		cout << "год выпуска: ";
		cin >> data;
		if (chek(data))
		{
			year = stoi(data);
			if(year > systemYear || year < 1800) continue;
			system("cls");
			data = "";
			break;
		}
	}
	
	while (true)
	{
		if (data != "")
		{
			system("cls");
			cout << "Ошибка, повтоите ввод\n";
		}
		cout << "обьем двигателя (см.куб): ";
		cin >> data;
		if (chek(data))
		{
			engine_capacity = stoi(data);
			if(engine_capacity < 0) continue;
			system("cls");
			data = "";
			break;
		}
	}
	
	while (true)
	{
		if (data != "")
		{
			system("cls");
			cout << "Ошибка, повтоите ввод\n";
		}
		cout << "Расстояние прогона (км): ";
		cin >> data;
		if (chek(data))
		{
			distance = stoi(data);
			if (distance < 0) continue;
			system("cls");
			data = "";
			break;
		}
	}

	cout << coast + total_coast(systemYear, year, distance, engine_capacity);

	return 0;
}


bool chek(const string data)
{
	if(data.length() > 10) return false;
	int dot_count = 0;
	for (char element : data)
	{
		if (element == '.')
		{
			dot_count++;
			if (dot_count > 1) return false;
			continue;
		}
		if (element < '0' || element > '9') return false;
	}
	return true;
}

float total_coast(const int system_year, const int year, const int distance, const int engine_capacity)
{
	float coast = 0;

	coast += distance * 0.5;
	if (system_year - year <= 3) coast += engine_capacity * 0.6;
	else if (system_year - year < 10 && engine_capacity < 2500) coast += engine_capacity * 0.35;
	else if (system_year - year < 10 && engine_capacity >= 2500) coast += engine_capacity * 0.6;
	else if (system_year - year < 14) coast += engine_capacity * 0.6;
	else coast += engine_capacity * 2;

	return coast;
}