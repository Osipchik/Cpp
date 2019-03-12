
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct list
{
	int number;
	string type;
	string name;
	string data;
	string cond;
};

list* addstruct(list *newlist, int size);
void fill_list(list *newlist, int size, ifstream &fin);
void show_list(list *newlist, int size);
void sort(list *newlist, int size);
void addtolist(list *newlist, int size);
void chengelist(list *newlist, int n);
list* deletelist(list *newlist, int nam, int &size);

int main()
{
	ifstream fin("D:\\Visual Application\\start.txt");
	list *newlist = 0;

	int size = 0;
	/// заполнение из файла
	while (!fin.eof())  
	{
		newlist = addstruct(newlist, size);
		fill_list(newlist, size, fin);
		size++;
	}
	fin.close();

	int decision = 0;
	do
	{
		show_list(newlist, size);
		cout << "\n save: 0 \n add to list: 1 \n delete list: 2 \n";
		cin >> decision;
		system("cls");

		if (decision == 1)
		{
			newlist = addstruct(newlist, size);
			addtolist(newlist, size);
			size++;
		}
		if (decision == 2)
		{
			int num;
			cout << "\n input number: ";
			cin >> num;
			newlist = deletelist(newlist, num, size);
			//size -= 1;
		}
	} while (decision != 0);

	
	sort(newlist, size);
	show_list(newlist, size);
	cout << endl;
	
	ofstream fout;
	fout.open("D:\\Visual Application\\result.txt");

	for (int i = 0; i < size; i++) /// сохранение в новый файл
	{
		fout << newlist[i].type << '\t';
		fout << newlist[i].name << '\t';
		fout << newlist[i].data << '\t';
		fout << newlist[i].cond << '\n';
	}
	fout.close();

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
void fill_list(list *newlist, int size, ifstream &fin)
{
	newlist[size].number = size + 1;
	fin >> newlist[size].type;
	fin >> newlist[size].name;
	fin >> newlist[size].data;
	fin >> newlist[size].cond;
}
void addtolist(list *newlist, int size)
{
	newlist[size].number = size + 1;
	cout << "\n type: ";
	cin >> newlist[size].type;
	cout << "\n name: ";
	cin >> newlist[size].name;
	cout << "\n data: ";
	cin >> newlist[size].data;
	cout << "\n condition: ";
	cin >> newlist[size].cond;
}
void show_list(list *newlist, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << endl;
		cout << newlist[i].number << " " << newlist[i].type << '\t' << newlist[i].name << '\t' << newlist[i].data << '\t' << newlist[i].cond;
	}
}
void sort(list *newlist, int size)
{
	for (int i = 0; i < size; i++)
	{
		string same = newlist[i].type;
		
		int temp_number;
		string temp_type;
		string temp_name;
		string temp_data;
		string temp_cond;

		int j = i + 1;
		
		while (j < size)
		{
			if (same == newlist[j].type)
			{
				temp_number = newlist[i + 1].number;
				temp_type = newlist[i + 1].type;
				temp_name = newlist[i + 1].name;
				temp_data = newlist[i + 1].data;
				temp_cond = newlist[i + 1].cond;

				newlist[i + 1].number = newlist[j].number;
				newlist[i + 1].type = newlist[j].type;
				newlist[i + 1].name = newlist[j].name;
				newlist[i + 1].data = newlist[j].data;
				newlist[i + 1].cond = newlist[j].cond;

				newlist[j].number = temp_number;
				newlist[j].type = temp_type;
				newlist[j].name = temp_name;
				newlist[j].data = temp_data;
				newlist[j].cond = temp_cond;
			}
			j++;
		}
	}
}
void chengelist(list *newlist, int n)
{
	system("cls");
	cout << "\n name: ";
	cin >> newlist[n].type;
	cout << "\n amount: ";
	cin >> newlist[n].name;
	cout << "\n coast: ";
	cin >> newlist[n].data;
	cout << "\n data: " << endl;
	cin >> newlist[n].cond;
}
list* deletelist(list *newlist, int num, int &size)
{
	int Nb = 0;
	while (true)
	{
		if (num == newlist[Nb].number) break;
		if (Nb == size)
		{
			cout << "\n list not found ";
			return newlist;
		}
		Nb++;
	}
	size -= 1;
	list *copylist = new list[size];
	int i = 0;
	while (i < Nb)
	{
		copylist[i].number = newlist[i].number;
		copylist[i].type = newlist[i].type;
		copylist[i].name = newlist[i].name;
		copylist[i].data = newlist[i].data;
		copylist[i].cond = newlist[i].cond;
		i++;
	}
	i += 1;
	while (i < size + 1)
	{
		copylist[i - 1].number = newlist[i].number - 1;
		copylist[i - 1].type = newlist[i].type;
		copylist[i - 1].name = newlist[i].name;
		copylist[i - 1].data = newlist[i].data;
		copylist[i - 1].cond = newlist[i].cond;
		i++;
	}
	delete[] newlist;
	return copylist;
}