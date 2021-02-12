#include "stdafx.h"
#include <iostream>
#include <fstream>
#include<vector>
#include <string>
using namespace std;

void add();
void show_all();
void find_by_name();
void find_by_tybe();
void find_by_shelf();
void update();
void remove();
void undo_state();
void redo_state();
void undo_operation();
void redo_operation();
int get_unique_id();
void save();
void open();
void close();
void sort_price_desc();
void sort_price_asc();
void counting(int id,string name,int amount, string price_, string tybe, string shelf_numper);
void show_top_five();
void remove_counting(string name);
//-----------------------------------
bool contining();
bool check_to_save(int count);
void showing();

int main()
{
	open();
	show_all();
	
	bool flag = true, undo = false;;
	short choies,counter=0;
	
	while (flag) {
		cout << "\n\n\nto add press 1\nto disblay data press 2\nto delete press 3\nto update press 4\nto save press 5\nto undo press 6\nto redo press 7\n";
		cin >> choies;
		system("cls");
		switch (choies)
		{
		case 1:
			system("cls");
			undo_state();
			add();
			++counter;
			if (check_to_save(counter))
				counter = 0;
			break;
		case 2:
			system("cls");
			showing();
			break;
		case 3:
			system("cls");
			undo_state();
			remove();
			++counter;
			if (check_to_save(counter))
				counter = 0;
			break;
		case 4:
			system("cls");
			undo_state();
			update();
			++counter;
			if (check_to_save(counter))
				counter = 0;
			break;
		case 5:
			system("cls");
			save();
			break;
		case 6:
			system("cls");
			if (!undo) {
				undo_operation();
				undo = true;
			}else
				cout << "\n sorry cant be undo";
			break;
		case 7:
			system("cls");
			if (undo)
			{
				redo_operation();
				undo = false;
			}
			else
				cout << "\n sorry cant be redo";
			
			break;
		default:
			cout << "sorry your choies is not listed\n";
			break;
		}

		
		flag = contining();
		system("cls");
	}
	close();
	return 0;
}


void add()
{
	ofstream file("file.txt", ios::app);;
	int product_id = get_unique_id();
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num;

	cout << "inter the product name :"; cin >> product_name;
	cout << "inter the product amount :"; cin >> product_amount;
	cout << "inter the product price :"; cin >> price;
	cout << "inter the product tybe :"; cin >> tybe_of_product;
	cout << "inter the product shelf number :"; cin >> shelf_num;

	file << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";

	file.close();
}

void show_all()
{

	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num;
	fstream file;
	file.open("file.txt", ios::in);

	while (!file.eof())
	{
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;
		if (product_id != NULL)
		{
			cout << product_id << "\t" << product_name << "\t" << product_amount << "\t";
			cout << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
		}


	}

	file.close();
}

void find_by_name()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num, search_name;
	fstream file;
	file.open("file.txt", ios::in);
	cout << "enter the name : "; cin >> search_name;

	while (!file.eof())
	{
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;


		if (search_name == product_name  && product_id != NULL)
		{
			cout << product_id << "\t" << product_name << "\t" << product_amount << "\t";
			cout << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
			counting(product_id, product_name, product_amount, price, tybe_of_product, shelf_num);
		}

		
	}


	file.close();
}

void find_by_tybe()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num, search_tybe;
	fstream file;
	file.open("file.txt", ios::in);
	cout << "enter the tybe : "; cin >> search_tybe;
	while (!file.eof())
	{
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;

		if (search_tybe == tybe_of_product && product_id != NULL)
		{
			cout << product_id << "\t" << product_name << "\t" << product_amount << "\t";
			cout << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
			counting(product_id, product_name, product_amount, price, tybe_of_product, shelf_num);
		}

	}
	file.close();
}

void find_by_shelf()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num, search_shelf;
	fstream file;
	file.open("file.txt", ios::in);
	cout << "enter the shelf number : "; cin >> search_shelf;
	while (!file.eof())
	{
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;

		if (search_shelf == shelf_num && product_id != NULL)
		{
			cout << product_id << "\t" << product_name << "\t" << product_amount << "\t";
			cout << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
			counting(product_id, product_name, product_amount, price, tybe_of_product, shelf_num);
		}

	}
	file.close();
}

void update()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num, update_name;
	fstream file, temp;
	file.open("file.txt", ios::in);
	temp.open("temp.txt", ios::out);

	cout << "enter name of the product : "; cin >> update_name;

	while (!file.eof()) {
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;

		if (update_name == product_name && product_id != NULL)
		{
			cout << "inter the " << product_name << " amount :"; cin >> product_amount;
			cout << "inter the " << product_name << " price :"; cin >> price;
			cout << "inter the " << product_name << " tybe :"; cin >> tybe_of_product;
			cout << "inter the " << product_name << " shelf number :"; cin >> shelf_num;
			temp << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
		}
		else {
			if (product_id != NULL)
				temp << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
		}
	}
	file.close();
	temp.close();
	file.open("file.txt", ios::out);
	temp.open("temp.txt", ios::in);

	while (!temp.eof())
	{
		product_id = NULL;
		temp >> product_id;
		temp >> product_name;
		temp >> product_amount;
		temp >> price;
		temp >> tybe_of_product;
		temp >> shelf_num;

		if (product_id != NULL)
			file << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
	}
	file.close();
	temp.close();
	remove("temp.txt");
}

void remove()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num, update_name;
	fstream file, temp;
	file.open("file.txt", ios::in);
	temp.open("temp.txt", ios::out);

	cout << "enter name of the product : "; cin >> update_name;

	while (!file.eof()) {
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;

		if (update_name == product_name && product_id != NULL)
		{
			continue;
		}
		else {
			if (product_id != NULL)
				temp << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
		}
	}
	file.close();
	temp.close();
	file.open("file.txt", ios::out);
	temp.open("temp.txt", ios::in);

	while (!temp.eof())
	{
		product_id = NULL;
		temp >> product_id;
		temp >> product_name;
		temp >> product_amount;
		temp >> price;
		temp >> tybe_of_product;
		temp >> shelf_num;

		if (product_id != NULL)
			file << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
	}
	file.close();
	temp.close();
	remove_counting(update_name);
	remove("temp.txt");
}

void undo_state()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num;
	fstream file, undo;
	file.open("file.txt", ios::in);
	undo.open("undo.txt", ios::out);
	while (!file.eof())
	{
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;
		if (product_id != NULL)
		{
			undo << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
		}
	}
	file.close();
	undo.close();
}

void redo_state()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num;
	fstream file, redo;
	file.open("file.txt", ios::in);
	redo.open("redo.txt", ios::out);
	while (!file.eof())
	{
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;
		if (product_id != NULL)
		{
			redo << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
		}
	}
	file.close();
	redo.close();
}

void undo_operation()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num;
	fstream file, undo;
	redo_state();
	file.open("file.txt", ios::out);
	undo.open("undo.txt", ios::in);
	while (!undo.eof())
	{
		product_id = NULL;
		undo >> product_id;
		undo >> product_name;
		undo >> product_amount;
		undo >> price;
		undo >> tybe_of_product;
		undo >> shelf_num;
		if (product_id != NULL)
			file << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
	}
	file.close();
	undo.close();
	remove("undo.txt");
}

void redo_operation()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num;
	fstream file, redo;
	undo_state();
	file.open("file.txt", ios::out);
	redo.open("redo.txt", ios::in);
	while (!redo.eof())
	{
		product_id = NULL;
		redo >> product_id;
		redo >> product_name;
		redo >> product_amount;
		redo >> price;
		redo >> tybe_of_product;
		redo >> shelf_num;
		if (product_id != NULL)
			file << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
	}
	file.close();
	redo.close();
	remove("redo.txt");
}

int get_unique_id()
{
	string line, z;
	short c = 0;
	ifstream file("file.txt", ios::in);
	while (getline(file, line))
	{
		z = line.substr(0, line.find_first_of('\t'));
		c++;
	}
	file.close();
	if (c == 0)
	return 1;

	int i = stoi(z);  // string to integer           to_string(int||float...);
	return ++i;
}

void save()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num;
	fstream file, saved;
	file.open("file.txt", ios::in);
	saved.open("main.txt", ios::out);
	while (!file.eof())
	{
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;
		if (product_id != NULL)
			saved << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
	}
	file.close();
	saved.close();
}

void open()
{
	int product_id;
	string product_name;
	int product_amount;
	string price, tybe_of_product, shelf_num;
	fstream file, saved;
	file.open("file.txt", ios::out);
	saved.open("main.txt", ios::in);
	while (!saved.eof())
	{
		product_id = NULL;
		saved >> product_id;
		saved >> product_name;
		saved >> product_amount;
		saved >> price;
		saved >> tybe_of_product;
		saved >> shelf_num;
		if (product_id != NULL)
			file << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\n";
	}
	file.close();
	saved.close();
}

void close()
{
	save();
	remove("file.txt");
	remove("undo.txt");
	remove("redo.txt");
}

void sort_price_desc()
{
	int product_id[50] = { NULL }, c = 0;
	string product_name[50];
	int product_amount[50];
	string price[50], tybe_of_product[50], shelf_num[50];
	fstream file;
	file.open("file.txt", ios::in);
	
	while (!file.eof())
	{
		product_id[c] = NULL;
		file >> product_id[c];
		file >> product_name[c];
		file >> product_amount[c];
		file >> price[c];
		file >> tybe_of_product[c];
		file >> shelf_num[c];
		++c;
	}
	
	for (short i = 0; i < c-1; i++)
	{
		for (short j = 0; j < c-1; j++)
		{
			if (price[i] < price[j])
			{
				swap(product_id[i], product_id[j]);
				swap(product_name[i], product_name[j]);
				swap(product_amount[i], product_amount[j]);
				swap(price[i], price[j]);
				swap(tybe_of_product[i], tybe_of_product[j]);
				swap(shelf_num[i], shelf_num[j]);
			}
		}
	}

	for (short j = 0; j < c-1 ; j++)
	{
		if (product_id != 0)
		{
			cout << product_id[j] << "\t" << product_name[j] << "\t" << product_amount[j] << "\t";
			cout << price[j] << "\t" << tybe_of_product[j] << "\t" << shelf_num[j] << "\n";
		}
	}
	file.close();
}

void sort_price_asc()
{
	int product_id[50] = { NULL }, c = 0;
	string product_name[50];
	int product_amount[50];
	string price[50], tybe_of_product[50], shelf_num[50];
	fstream file;
	file.open("file.txt", ios::in);

	while (!file.eof())
	{
		product_id[c] = NULL;
		file >> product_id[c];
		file >> product_name[c];
		file >> product_amount[c];
		file >> price[c];
		file >> tybe_of_product[c];
		file >> shelf_num[c];
		++c;
	}

	for (short i = 0; i < c - 1; i++)
	{
		for (short j = 0; j < c - 1; j++)
		{
			if (price[i] > price[j])
			{
				swap(product_id[i], product_id[j]);
				swap(product_name[i], product_name[j]);
				swap(product_amount[i], product_amount[j]);
				swap(price[i], price[j]);
				swap(tybe_of_product[i], tybe_of_product[j]);
				swap(shelf_num[i], shelf_num[j]);
			}
		}
	}

	for (short j = 0; j < c - 1; j++)
	{
		if (product_id != 0)
		{
			cout << product_id[j] << "\t" << product_name[j] << "\t" << product_amount[j] << "\t";
			cout << price[j] << "\t" << tybe_of_product[j] << "\t" << shelf_num[j] << "\n";
		}
	}
	file.close();
}

void counting(int id, string name, int amount, string price_, string tybe, string shelf_numper)
{
	int product_id;
	string product_name;
	int product_amount;
	int best;
	bool ex = false;
	string price, tybe_of_product, shelf_num;
	fstream  count,temp;
	count.open("count.txt", ios::in );
	temp.open("temp.txt", ios::out);

	 
	while (!count.eof())
	{
		product_id = NULL;
		count >> product_id;
		count >> product_name;
		count >> product_amount;
		count >> price;
		count >> tybe_of_product;
		count >> shelf_num;
		count >> best;
		
		
		if (id == product_id  && product_id != NULL)
		{
			ex = true;
			temp << product_id << "\t" << product_name << "\t" << amount << "\t" << price_ << "\t" << tybe << "\t" << shelf_numper << "\t" << ++best << "\n";
			
		}
		else if(product_id != NULL)
			temp << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\t" << best << "\n";
	}
	count.close();
	temp.close();
	
	if (ex)
	{
		count.open("count.txt", ios::out);
		 temp.open("temp.txt", ios::in);
		while (!temp.eof())
		{
			product_id = NULL;
			temp >> product_id;
			temp >> product_name;
			temp >> product_amount;
			temp >> price;
			temp >> tybe_of_product;
			temp >> shelf_num;
			temp >> best;

			if (product_id != NULL)
			count << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\t" << best << "\n";
		}
		temp.close();
		count.close();
	}

	if (!ex) {
		
		count.open("count.txt", ios::app);
		count << id << "\t" << name << "\t" << amount << "\t" << price_ << "\t" << tybe << "\t" << shelf_numper << "\t" << "0" << "\n";
		count.close();
	}
	remove("temp.txt");
}

void show_top_five()
{
	int product_id[50] = { NULL }, c = 0;
	string product_name[50];
	int product_amount[50];
	string price[50], tybe_of_product[50], shelf_num[50];
	int best[50];
	fstream file;
	file.open("count.txt", ios::in);

	while (!file.eof())
	{
		product_id[c] = NULL;
		file >> product_id[c];
		file >> product_name[c];
		file >> product_amount[c];
		file >> price[c];
		file >> tybe_of_product[c];
		file >> shelf_num[c];
		file >> best[c];
		++c;
	}

	for (short i = 0; i < c - 1; i++)
	{
		for (short j = 0; j < c - 1; j++)
		{
			if (best[i] > best[j])
			{
				swap(product_id[i], product_id[j]);
				swap(product_name[i], product_name[j]);
				swap(product_amount[i], product_amount[j]);
				swap(price[i], price[j]);
				swap(tybe_of_product[i], tybe_of_product[j]);
				swap(shelf_num[i], shelf_num[j]);
				swap(best[i], best[j]);
			}
		}
	}

	for (short j = 0; j < c - 1 && j<5; j++)
	{
		if (product_id != 0)
		{
			cout << product_id[j] << "\t" << product_name[j] << "\t" << product_amount[j] << "\t";
			cout << price[j] << "\t" << tybe_of_product[j] << "\t" << shelf_num[j] <<"\t"<< best[j]<< "\n";
		}
	}
	file.close();
}

void remove_counting(string name)
{
	int product_id;
	string product_name;
	int product_amount;
	int best;
	bool ex = false;
	string price, tybe_of_product, shelf_num;
	fstream  file, temp;
	file.open("count.txt", ios::in);
	temp.open("temp.txt", ios::out);


	while (!file.eof()) {
		product_id = NULL;
		file >> product_id;
		file >> product_name;
		file >> product_amount;
		file >> price;
		file >> tybe_of_product;
		file >> shelf_num;
		file >> best;

		if (name == product_name && product_id != NULL)
		{
			continue;
		}
		else {
			if (product_id != NULL)
				temp << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num <<"\t"<< best <<"\n";
		}
	}
	file.close();
	temp.close();
	file.open("count.txt", ios::out);
	temp.open("temp.txt", ios::in);

	while (!temp.eof())
	{
		product_id = NULL;
		temp >> product_id;
		temp >> product_name;
		temp >> product_amount;
		temp >> price;
		temp >> tybe_of_product;
		temp >> shelf_num;
		temp >> best;

		if (product_id != NULL)
			file << product_id << "\t" << product_name << "\t" << product_amount << "\t" << price << "\t" << tybe_of_product << "\t" << shelf_num << "\t" << best << "\n";
	}
	file.close();
	temp.close();
	remove("temp.txt");
}

bool contining()
{
	char continuing = NULL;
	cout << "\ndo you want to continue (Y/N) :\n"; cin >> continuing;
	if (continuing == 'y' || continuing == 'Y')
		return true;
	else if (continuing == 'n' || continuing == 'N')
		return false;
	else
		contining();
}

bool check_to_save(int count)
{
	if (count >=5)
	{
		save();
		cout << "data saved\n";
		return true;
	}
	return false;
}

void showing()
{
	cout << "\n\n\nto show all press 1\nto serch by name press 2\nto serch by tybe 3\nto serch by shelf 4\n";
	short choies;
	cin >> choies;
	switch (choies)
	{
	case 1:
		show_all();
		break;
	case 2:
		find_by_name();
		break;
	case 3:
		find_by_tybe();
		break;
	case 4:
		find_by_shelf();
		break;
	default:
		cout << "sorry your choies is not listed \n";
		break;
	}
}


