
#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

struct list
{
	int number;
	string name;
	string amount;
	double coast;
	string data;
};

list* addstruct(list *newlist, int size);
void fill_list(list *newlist, int size);
void showlist(list *newlist, int size);
void sort(list *newlist, int size);
void showone(list *newlist, int numb);
void show100list(list *newlist, int size);         ///  отсортированные, больше 100000
void chengelist(list *newlist, int n);
list* deletelist(list *newlist, int Nb, int &size);

int main()
{
	setlocale(LC_ALL, "ru");
	int decision;
	int size = 0;
	list *newlist = 0;

	do
	{
		newlist = addstruct(newlist, size);
		fill_list(newlist, size);

		size++;
		system("cls");

		do
		{
			cout << "\n exit press: 0 \n continue press: 1 \n show all list press: 2 \n show one list press: 3"
			     << "\n change list, press: 4 \n delete list press 5 \n";
			cin >> decision;
			system("cls");

			if (decision == 2) showlist(newlist, size);
			if (decision == 3)
			{
				cout << "\n input number (available numbers 1 - " << size << "): ";
				int num;
				cin >> num;
				showone(newlist, num - 1);
			}
			if (decision == 4)
			{
				cout << "\n input number (available numbers 1 - " << size << "): ";
				int n;
				cin >> n;
				chengelist(newlist, n - 1);
			}
			if (decision == 5)
			{
				int Nb;
				cout << "\n input number (available numbers 1 - " << size << "): ";
				cin >> Nb;
				newlist = deletelist(newlist, Nb - 1, size);
			}
		} while (decision > 1);

		system("cls");
	} while (decision != 0);

	sort(newlist, size);
	showlist(newlist, size);

	cout << endl << endl;
	show100list(newlist, size);

	delete[] newlist;
	return 0;
}

list* addstruct(list *newlist, int size)
{
	if (size == 0)
		newlist = new list[size + 1];
	else
	{
		list *templist = new list[size + 1];
		
		for (int i = 0; i < size; i++)
			templist[i] = newlist[i];
		delete[] newlist;
		
		newlist = templist;
	}
	return newlist;
}
void fill_list(list *newlist, int size)
{
	newlist[size].number = size + 1;
	system("cls");
	cout << "\n name: ";
	cin >> newlist[size].name;
	system("cls");
	cout << "\n amount: ";
	cin >> newlist[size].amount;
	system("cls");
	cout << "\n coast: ";
	cin >> newlist[size].coast;
	system("cls");
	cout << "\n data: " << endl;
	cin >> newlist[size].data;
	system("cls");
}
void showlist(list *newlist, int size)
{
	cout << endl << " Nb " << '\t' << " name " << '\t' << "amount" << '\t' << "coast" << '\t' << "data";
	for (int i = 0; i < size; i++)
		cout << endl << " " << newlist[i].number << '\t' << newlist[i].name << '\t' << newlist[i].amount << '\t'
		     << newlist[i].coast << '\t' << newlist[i].data;
	cout << endl;
}
void showone(list *newlist, int numb)
{
	cout << endl << " Nb " << " name " << '\t' << "amount" << '\t' << "coast" << '\t' << "data";
	cout << endl << " " << newlist[numb].number << '\t' << newlist[numb].name << '\t' << newlist[numb].amount << '\t'
		         << newlist[numb].coast << '\t' << newlist[numb].data;
	cout << endl;
}
void sort(list *newlist, int size)
{
	for (int i = 1; i < size; i++)
	{
		double coast = newlist[i].coast;
		string name = newlist[i].name;
		string amount = newlist[i].amount;
		string data = newlist[i].data;
		int number = newlist[i].number;
		int j = i - 1;

		while (coast > newlist[j].coast)
		{
			newlist[j + 1] = newlist[j];
			j--;
			if (j < 0) break;
		}
		newlist[j + 1].coast = coast;
		newlist[j + 1].name = name;
		newlist[j + 1].amount = amount;
		newlist[j + 1].data = data;
		newlist[j + 1].number = number;
	}
}
void show100list(list *newlist, int size)
{
	int size100 = 0;
	for (int i = 0; i < size; i++)
		if (newlist[i].coast > 100000)
			size100++;
	showlist(newlist, size100);
}
void chengelist(list *newlist, int n)
{
	system("cls");
	cout << "\n name: ";
	cin >> newlist[n].name;
	cout << "\n amount: ";
	cin >> newlist[n].amount;
	cout << "\n coast: ";
	cin >> newlist[n].coast;
	cout << "\n data: " << endl;
	cin >> newlist[n].data;
}
list* deletelist(list *newlist, int Nb, int &size)
{
	size -= 1;
	list *copylist = new list[size];
	int i = 0;
	while (i < Nb)
	{
		copylist[i].number = newlist[i].number;
		copylist[i].name = newlist[i].name;
		copylist[i].amount = newlist[i].amount;
		copylist[i].coast = newlist[i].coast;
		copylist[i].data = newlist[i].data;
		i++;
	}
	i += 1;
	while (i < size + 1)
	{
		copylist[i - 1].number = newlist[i].number - 1;
		copylist[i - 1].name = newlist[i].name;
		copylist[i - 1].amount = newlist[i].amount;
		copylist[i - 1].coast = newlist[i].coast;
		copylist[i - 1].data = newlist[i].data;
		i++;
	}
	delete[] newlist;
	return copylist;
}