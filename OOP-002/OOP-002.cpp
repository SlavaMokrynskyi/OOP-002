#include <iostream>

using namespace std;

class Subscriber
{
	char* name;
	string home_phone;
	string work_phone;
	string user_phone;
	string info;
public:
	Subscriber(string home_phone, string work_phone, string user_phone, string info)
	{
		this->name = new char[100];
		cout << "Enter name of your subscriber (max symbols 100): ";
		cin.getline(name, 100);
		this->home_phone = home_phone;
		this->user_phone = user_phone;
		this->work_phone = work_phone;
		this->info = info;
	}
	Subscriber() : Subscriber("none", "none", "none", "none") {}
	void ShowContact(Subscriber sub)
	{
		cout << "Name: " << sub.name << "\n";
		cout << "Home phone: " << sub.home_phone << "\n";
		cout << "Work phone: " << sub.work_phone << "\n";
		cout << "User phone: " << sub.user_phone << "\n";
		cout << "Info: " << sub.info << "\n";
	}
	Subscriber* AddNewContact(Subscriber* phone_book, int count_of_subs, Subscriber new_subscriber)
	{
		Subscriber* new_phone_book = new Subscriber[count_of_subs + 1];
		
		for (int i = 0; i < count_of_subs; i++)
		{
			new_phone_book[i] = phone_book[i];
		}
		new_phone_book[count_of_subs].name = new_subscriber.name;
		new_phone_book[count_of_subs].home_phone = new_subscriber.home_phone;
		new_phone_book[count_of_subs].user_phone = new_subscriber.user_phone;
		new_phone_book[count_of_subs].work_phone = new_subscriber.work_phone;
		new_phone_book[count_of_subs].info = new_subscriber.info;
		delete[] phone_book;
		return new_phone_book;
	}
	Subscriber* DeleteContact(Subscriber* phone_book, int count_of_subs, int index)
	{
		if (index < 0 || index > count_of_subs)
		{
			cout << "Invalid index of contact!" << endl;
			return phone_book;
		}
		Subscriber* new_phone_book = new Subscriber[count_of_subs - 1];
		for (int i = 0; i < index; i++)
		{
			new_phone_book[i] = phone_book[i];
		}
		for (int i = index; i < count_of_subs - 1; i++)
		{
			new_phone_book[i] = phone_book[i + 1];
		}
		return new_phone_book;
	}
	void ShowIndexByPIB(Subscriber* phone_book,int count_of_subs, char* name)
	{
		for (int i = 0; i < count_of_subs; i++)
		{
			if (phone_book[i].name == name)
			{
				cout << "Index: " << i;
			}
		}
	}
	void ShowAllContacts(Subscriber* phone_book, int count_of_subs)
	{
		for (int i = 0; i < count_of_subs; i++)
		{
			cout << i + 1 << " contact: " << "\n";
			phone_book[i].ShowContact(phone_book[i]);
			cout << "\n";
		}
	}
	~Subscriber()
	{
		delete[] name;
	}
};


int main()
{
	int count_of_subs;
	cout << "Enter hom much people in your phone book: ";
	cin >> count_of_subs;
	Subscriber* phone_book = new Subscriber[count_of_subs];
	delete[] phone_book;
}