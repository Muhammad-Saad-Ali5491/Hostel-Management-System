#pragma once
#include<fstream>
#include<sstream>
#include<iostream>
#include <string>
#include"ClearAndWait.h"
using namespace std;
class rooms
{
private:
	int roomNo;
	int floorNo;
	bool available;
	double price;
public:
	rooms()
	{
		roomNo = 0;
		floorNo = 0;
		available = true;
		price = 0.0;
	}
	void addRoom(int roomNo, int floorNo, double price);
	void displayAllRoom();
	void ModifyRoom();
	void ViewAvailableRooms();
	void availableRoom(string inputR, string inputF);
	int searchRoom(int inputR, int inputF);
	bool checkAvailableRooms()
	{
		ifstream fin("room.txt");
		if (!fin)
		{
			cout << "File not found" << endl;

		}
		else
		{
			int f, r, p, a;
			int check = false;
			while (fin >> f >> r >> a >> p)
			{
				if (a == 1 || a == -1)
				{
					check = true;
				}
			}
			if (check == true)
			{
				return true;
			}
			else {
				return false;
			}
		}
		fin.close();
	}
};
void rooms::addRoom(int roomNo, int floorNo, double price)
{
	this->roomNo = roomNo;
	this->floorNo = floorNo;
	this->available = true;
	this->price = price;
	ofstream fout("room.txt", ios::app);
	if (!fout)
	{
		cout << "file doesn't exist" << endl;
	}
	else
	{
		fout << this->floorNo << "-" << this->roomNo << "-" << this->available << "-" << this->price << endl;
	}

}
void rooms::displayAllRoom()
{
	ifstream fin("room.txt");
	if (!fin)
	{
		cout << "File not found" << endl;

	}
	else
	{
		int f, r, p, a;
		while (fin >> f >> r >> a >> p)
		{
			cout << "Room No. " << f << -r << ",Floor No. " << f << ", Price : " << -p << ", Availability: " << (a ? "[Available]" : "[Not Available]") << endl;
		}
	}
	fin.close();
}
void rooms::ModifyRoom() {
	fstream file("room.txt", ios::in | ios::out);
	if (!file.is_open()) {
		cout << "File not found" << endl;
		return;
	}

	string f, r, p, a;
	string inputR, inputF;
	cout << "Enter Floor no. " << endl;
	cin >> inputF;
	cout << "Enter Room no. " << endl;
	cin >> inputR;
	clearScreen();
	file.seekg(0, ios::beg);

	bool roomFound = false;

	while (!file.eof()) {
		streampos currentPos = file.tellg(); // Save the current position

		getline(file, f, '-');
		getline(file, r, '-');
		getline(file, a, '-');
		getline(file, p, '\n');

		if (inputR == r && inputF == f) {
			roomFound = true;

			int mr = 0;
			cout << "Enter What you want to Modify" << endl;
			cout << "1) Room No." << endl;
			cout << "2) Floor No." << endl;
			cout << "3) Availability" << endl;
			cout << "4) Price" << endl;
			cout << "Press 9 to Exit" << endl;
			cin >> mr;
			clearScreen();

			if (mr == 1) {
				string Rn;
				cout << "Enter new room no." << endl;
				cin >> Rn;
				r = Rn;
			}
			else if (mr == 2) {
				string Fn;
				cout << "Enter new Floor no." << endl;
				cin >> Fn;
				f = Fn;
			}
			else if (mr == 3) {
				bool ava;
				cout << "Enter Availability (1 or 0)" << endl;
				cin >> ava;
				a = to_string(ava);
			}
			else if (mr == 4) {
				string P;
				cout << "Enter new Price" << endl;
				cin >> P;
				p = P;
			}
			else if (mr == 9) {
				break;
			}
			else {
				cout << "Wrong entry, please try again" << endl;
				waitForEnter();
				clearScreen();
				continue;
			}

			// Move the file cursor back to the beginning of the line and overwrite the existing data
			file.seekp(currentPos);
			file << f << "-" << r << "-" << a << "-" << p;
			break; // Room modified, exit the loop
		}
		else {
			cout << "Data not found" << endl;
		}
	}

	file.close();

	if (roomFound) {
		cout << "Room modified successfully" << endl;
	}

}
void rooms::ViewAvailableRooms()
{
	ifstream fin("room.txt");
	if (!fin)
	{
		cout << "File not found" << endl;

	}
	else
	{
		int f, r, p, a;
		while (fin >> f >> r >> a >> p)
		{
			if (a == 1 || a == -1)
			{
				cout << "Room No. " << f << -r << ",Floor No. " << f << ", Price : " << -p << ", Availability: " << (a ? "[Available]" : "[Not Available]") << endl;
			}
		}
	}
	fin.close();
}
void rooms::availableRoom(string inputR, string inputF) {
	fstream file("room.txt", ios::in | ios::out);
	if (!file.is_open()) {
		cout << "File not found" << endl;
		return;
	}
	string f, r, p, a;
	file.seekg(0, ios::beg);

	bool roomFound = false;

	while (!file.eof()) {
		streampos currentPos = file.tellg(); // Save the current position

		getline(file, f, '-');
		getline(file, r, '-');
		getline(file, a, '-');
		getline(file, p, '\n');

		if (inputR == r && inputF == f)
		{
			roomFound = true;
			a = to_string(0);
			file.seekp(currentPos);
			file << f << "-" << r << "-" << a << "-" << p;
			break; // Room modified, exit the loop
		}
	}

	file.close();

	if (roomFound) {
		cout << "Room modified successfully" << endl;
	}
	else {
		cout << "Data not found" << endl;
	}
}
int rooms::searchRoom(int inputR, int inputF) {
	fstream file("room.txt", ios::in | ios::out);
	if (!file.is_open()) {
		cout << "File not found" << endl;
		return 0.0;
	}
	string f, r, a, p;
	file.seekg(0, ios::beg);

	bool roomFound = false;

	while (!file.eof()) {
		streampos currentPos = file.tellg(); // Save the current position

		getline(file, f, '-');
		getline(file, r, '-');
		getline(file, a, '-');
		getline(file, p, '\n');
		if (to_string(inputR) == r && to_string(inputF) == f) {
			// Room found
			roomFound = true;
			a = to_string(1);
			file.seekp(currentPos);
			file << f << "-" << r << "-" << a << "-" << p;
			file.close(); // Close the file after modifying
			return stof(p); // Return the room price
			// No need for break, as return exits the function
		}
	}

	file.close(); // Close the file after checking all rooms

	// If the room is not found, you can return a special value like -1
	return -1;
}
