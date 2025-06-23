#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include"ClearAndWait.h"
#include"date.h"
#include"Room.h"
using namespace std;
struct node
{
	string name;
	string CNIC;
	string contact;
	string address;
	int room;
	int floor;
	int day, month, year;
	node* next;
	node* prev;
	node(string name, string CNIC, string contact, string address, int room, int floor, int day, int month, int year) : name(name), CNIC(CNIC), contact(contact), address(address), room(room), floor(floor), day(day), month(month), year(year), next(nullptr), prev(nullptr)
	{}
};
class costumer
{
private:
	node* head;
	node* tail;
public:
	rooms r;
	costumer() : head(nullptr), tail(nullptr) {}

	void addCostumer(string name, string CNIC, string contact, string address, int room, int floor, int day, int month, int year) {

		node* newNode = new node(name, CNIC, contact, address, room, floor, day, month, year);
		if (!head) {
			head = tail = newNode;
		}
		else {
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
	}
	void modifyCostumer() {
		string name, CNIC, contact, address;
		int room, floor, day, month, year;

		cout << "Enter customer name to modify: ";
		cin >> name;

		cout << "Enter customer CNIC to modify: ";
		cin >> CNIC;

		node* current = head;

		int n = 0, s = 0, t = 0;

		while (current != nullptr) {
			if (current->name == name && current->CNIC == CNIC) {
				t = 1;
				while (n != 9) {
					cout << "What would you like to Modify" << endl;
					cout << "1) Name" << endl;
					cout << "2) CNIC" << endl;
					cout << "3) Contact" << endl;
					cout << "4) Address" << endl;
					cout << "5) Room" << endl;
					cout << "6) Floor" << endl;
					cout << "7) Date" << endl;
					cout << "Press 9 to Exit" << endl;
					cin >> n;
					clearScreen();

					if (n == 1) {
						s = 1;
						cout << "Enter New Name: ";
						cin >> name;
						current->name = name;
						clearScreen();
					}
					else if (n == 2) {
						s = 1;
						cout << "Enter New CNIC: ";
						cin >> CNIC;
						current->CNIC = CNIC;
						clearScreen();
					}
					else if (n == 3) {
						s = 1;
						cout << "Enter New Contact: ";
						cin >> contact;
						current->contact = contact;
						clearScreen();
					}
					else if (n == 4) {
						s = 1;
						cout << "Enter New Address: ";
						cin >> address;
						current->address = address;
						clearScreen();
					}
					else if (n == 5) {
						s = 1;
						cout << "Enter New Room No: ";
						cin >> room;
						current->room = room;
						clearScreen();
					}
					else if (n == 6) {
						s = 1;
						cout << "Enter New Floor No: ";
						cin >> floor;
						current->floor = floor;
						clearScreen();
					}
					else if (n == 7) {
						s = 1;
						cout << "Enter New Day: ";
						cin >> day;
						current->day = day;
						clearScreen();
						cout << "Enter New Month: ";
						cin >> month;
						current->month = month;
						clearScreen();
						cout << "Enter New Year: ";
						cin >> year;
						current->year = year;
						clearScreen();
					}
					else if (n == 9) {
						break;  // Exit the loop
					}
					else {
						cout << "Wrong entry, try again" << endl;
						waitForEnter();
					}

					if (s == 1) {
						cout << "Updated successfully" << endl;
						waitForEnter();
						clearScreen();
						s = 0;
					}
				}
				break;  // Exit the loop once modifications are done
			}

			current = current->next;
		}

		if (t == 0) {
			cout << "Data not found" << endl;
			cin.ignore();
			waitForEnter();
			clearScreen();
		}
	}
	void removeCostumer(string name, string CNIC) {
		node* current = head;

		// Handle the case when the list is empty
		if (!current) {
			cout << "Customer not found." << endl;
			return;
		}

		// Handle the case when the customer to remove is the first node
		if (current->name == name && current->CNIC == CNIC) {
			head = current->next;
			if (head) {
				head->prev = nullptr;
			}
			else {
				// If head is null, it means there was only one node, so update tail as well
				tail = nullptr;
			}

			// Save removed customer information to a file
			saveRemovedCustomerToFile(current);

			delete current;
			cout << "Customer removed successfully." << endl;
			return;
		}

		// Search for the customer to remove
		while (current) {
			if (current->name == name && current->CNIC == CNIC) {
				// Adjust next and prev pointers of neighboring nodes
				if (current->prev) {
					current->prev->next = current->next;
				}
				else {
					// If there is no previous node, update head
					head = current->next;
				}

				if (current->next) {
					current->next->prev = current->prev;
				}
				else {
					// If there is no next node, update tail
					tail = current->prev;
				}

				// Save removed customer information to a file
				saveRemovedCustomerToFile(current);

				// Delete the current node
				delete current;
				cout << "Customer removed successfully." << endl;
				return;
			}
			current = current->next;
		}

		// Customer not found
		cout << "Customer not found." << endl;
	}
	void saveRemovedCustomerToFile(node* removedCustomer) {
		// Open the file for appending removed customer information
		ofstream file("history.txt", ios::app);

		if (!file) {
			cout << "Error opening file for removed customers." << endl;
			return;
		}

		// Write removed customer information to the file
		file << removedCustomer->name << ","
			<< removedCustomer->CNIC << ","
			<< removedCustomer->contact << ","
			<< removedCustomer->address << ","
			<< removedCustomer->room << ","
			<< removedCustomer->floor << ","
			<< removedCustomer->day << "-"
			<< removedCustomer->month << "-"
			<< removedCustomer->year << "\n";

		file.close();
	}
	void loadDataFromFile(costumer& customerList) {
		ifstream file("costumer.txt");

		if (!file.is_open()) {
			cout << "Error opening file: " << "customer.txt" << endl;
			return;
		}

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
			customerList.addCostumer(name, CNIC, contact, address, room, floor, day, month, year);
		}

		file.close();
	}
	void saveData() {
		node* current = head;
		ofstream file("costumer.txt", ios::out); // Open in truncation mode

		if (!file) {
			cout << "Error creating or opening the file." << endl;
			return;
		}

		while (current != nullptr) {
			file << current->name << ","
				<< current->CNIC << ","
				<< current->contact << ","
				<< current->address << ","
				<< current->room << ","
				<< current->floor << ","
				<< current->day << "-"
				<< current->month << "-"
				<< current->year << "\n";
			current = current->next;
		}

		file.close();
		cout << "Data saved successfully." << endl;
	}
	void resaveData() {
		node* current = head;
		ofstream file("costumer.txt", ios::out); // Open in truncation mode

		if (!file) {
			cout << "Error creating or opening the file." << endl;
			return;
		}

		while (current != nullptr) {
			file << current->name << ","
				<< current->CNIC << ","
				<< current->contact << ","
				<< current->address << ","
				<< current->room << ","
				<< current->floor << ","
				<< current->day << "-"
				<< current->month << "-"
				<< current->year << "\n";
			current = current->next;
		}

		file.close();
		cout << "Data saved successfully." << endl;
	}
	void display()
	{
		node* current = head;
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
			current = current->next;
		}

	}
	void searchCustomer(string name, string CNIC, int& bill, int& daysDifference) {
		node* current = head;

		// Handle the case when the list is empty
		if (!current) {
			cout << "Customer not found." << endl;
			return;
		}

		// Handle the case when the customer to remove is the first node
		if (current->name == name && current->CNIC == CNIC) {
			head = current->next;
			Date d1, d2;
			d1.day = current->day;
			d1.month = current->month;
			d1.year = current->year;
			cout << "enter today's day(day/month/year)" << endl;
			cin >> d2.day >> d2.month >> d2.year;
			daysDifference = calculateDaysBetweenDates(d1, d2) - 1;
			int price = r.searchRoom(current->room, current->floor);
			bill = (price * daysDifference);
			cout << "Customer found" << endl;
			return;
		}

		// Search for the customer to remove
		while (current) {
			if (current->name == name && current->CNIC == CNIC) {
				// Adjust next and prev pointers of neighboring nodes
				cout << "Customer found" << endl;
				Date d1, d2;
				d1.day = current->day;
				d1.month = current->month;
				d1.year = current->year;
				cout << "enter today's day(day/month/year)" << endl;
				cin >> d2.day >> d2.month >> d2.year;
				daysDifference = calculateDaysBetweenDates(d1, d2);
				float price = r.searchRoom(current->room, current->floor);
				bill = price * daysDifference;

				return;
			}
			current = current->next;
		}

		// Customer not found
		cout << "Customer not found." << endl;
	}
	~costumer() {
		while (head) {
			node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};


