#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Forward declaration of the Node struct
struct Node {
	string name;
	string CNIC;
	string contact;
	string address;
	int room;
	int floor;
	int day, month, year;
	Node* next;
	Node* prev;

	// Constructor

	Node(string name, string CNIC, string contact, string address, int room, int floor, int day, int month, int year)
		: name(name), CNIC(CNIC), contact(contact), address(address), room(room), floor(floor), day(day), month(month), year(year), next(nullptr), prev(nullptr)
	{}
};
class history
{
private:
	Node* top = nullptr;

public:
	void push(string name, string CNIC, string contact, string address, int room, int floor, int day, int month, int year)
	{
		Node* n = new Node(name, CNIC, contact, address, room, floor, day, month, year);
		if (!top)
		{
			top = n;
		}
		else
		{
			top->next = n;  // Update the next pointer of the new node
			n->prev = top;  // Update the prev pointer of the old top node
			top = n;        // Update the top pointer to the new node
		}
	}
	void popAll()
	{
		if (!top)
		{
			cout << "Stack is empty" << endl;
		}
		else
		{
			while (top != nullptr) {
				Node* current = top;
				top = top->prev;

				cout << current->name << ","
					<< current->CNIC << ","
					<< current->contact << ","
					<< current->address << ","
					<< current->room << ","
					<< current->floor << ","
					<< current->day << "-"
					<< current->month << "-"
					<< current->year << "\n";

				delete current;
			}

			resetHistoryFile();
		}
	}
	void resetHistoryFile() {
		ofstream file("history.txt", ofstream::trunc);
		file.close();
	}
	void loadDataFromFile(history& h) {
		fstream file("history.txt", ios::in);

		if (!file.is_open()) {
			cout << "Error opening file: " << "history.txt" << endl;
			return;
		}
		file.seekg(0, ios::beg);
		string line;
		while (getline(file, line)) {
			stringstream ss(line);
			string name, CNIC, contact, address;
			int room, floor, day, month, year;

			getline(ss, name, ',');
			getline(ss, CNIC, ',');
			getline(ss, contact, ',');
			getline(ss, address, ',');
			ss >> room;
			ss.ignore(); // Ignore the comma
			ss >> floor;
			ss.ignore(); // Ignore the comma
			ss >> day;
			ss.ignore(); // Ignore the slash
			ss >> month;
			ss.ignore(); // Ignore the slash
			ss >> year;

			// Add the customer to the linked list
			h.push(name, CNIC, contact, address, room, floor, day, month, year);
		}

		file.close();
	}
	void display()
	{
		if (!top)
		{
			cout << "Stack is Empty" << endl;
			return;
		}
		else
		{
			Node* current = top;
			while (current != nullptr) {
				cout << current->name << ","
					<< current->CNIC << ","
					<< current->contact << ","
					<< current->address << ","
					<< current->room << ","
					<< current->floor << ","
					<< current->day << "-"
					<< current->month << "-"
					<< current->year << "\n";
				current = current->prev;
			}
		}
	}

};


