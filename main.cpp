#include<iostream>
#include"introduction.h"
#include"MainMenu.h"
#include"ClearAndWait.h"
#include"costumer.h"
#include"Room.h"
#include"History.h"
using namespace std;
int main()
{
	int n = 0, m = 0, adch = 0, costumerS = 0, History = 0;
	bool check = false;
	intro();
	waitForEnter();
	clearScreen();
	costumer c;
	history h;
	rooms r;
	c.loadDataFromFile(c);
	//////////////////////////////////// SIGNUP/SIGNIN /////////////////////////////////////
	while (1)
	{
		menu();
		if (cin >> n)
		{
			clearScreen();
			if (n == 1)
			{
				signup();
				cout << "New Account Created Successfully" << endl;
				cin.ignore();
				waitForEnter();
				clearScreen();
				continue;
			}
			else if (n == 2)
			{
				check = login();
				clearScreen();
				break;
			}
			else {
				cout << "Wrong Entry" << endl;
				cin.ignore();
				waitForEnter();
				clearScreen();
				continue;
			}
		}

	}
	////////////////////////////////// MAIN MENUS //////////////////////////////////////////////
	while (m != 9)
	{
		if (check == true)
		{
			cout << "====================================" << endl;
			cout << "= Welcome to The Hostel Management =" << endl;
			cout << "====================================" << endl;
			cout << "1) Admin Options" << endl;
			cout << "2) Costumer Services" << endl;
			cout << "3) View History" << endl;
			cout << "Press '9' to Exit" << endl;
			cin >> m;
			clearScreen();
		}
		else
		{
			cout << "User Not Found" << endl;

			break;
		}
		///////////////////////////////////// MAIN MENU OPTIONS //////////////////////////////////////////////
		while (1)
		{
			if (m == 1)
			{
				cout << "============================" << endl;
				cout << "= Welcome to Admin Options =" << endl;
				cout << "============================" << endl;
				cout << "1) Add Rooms" << endl;
				cout << "2) Display All Rooms" << endl;
				cout << "3) Modify Room" << endl;
				cout << "Enter 9 to Exit" << endl;
				cin >> adch;
				clearScreen();
				//////////////////////////////ADMIN CONTROL////////////////////////////////////////

				if (adch == 1)
				{
					cout << "Add room no." << endl;
					int roomNo;
					cin >> roomNo;
					cout << "Enter floor no" << endl;
					int floorNo;
					cin >> floorNo;
					cout << "Enter price for this room" << endl;
					double price;
					cin >> price;
					r.addRoom(roomNo, floorNo, price);
					clearScreen();
				}
				else if (adch == 2)
				{
					r.displayAllRoom();
					cin.ignore();
					waitForEnter();
					clearScreen();
				}
				else if (adch == 3)
				{
					r.ModifyRoom();
					clearScreen();
				}
				else if (adch == 9)
				{
					break;
				}
				else
				{
					cout << "wrong entry try again" << endl;
					waitForEnter();
					clearScreen();
				}
			}
			///////////////////////////////////// COSTUMER SERVICES /////////////////////////////////////////
			else if (m == 2)
			{

				cout << "================================" << endl;
				cout << "= Welcome to Costumer Services =" << endl;
				cout << "================================" << endl;
				cout << "1) Add Costumer" << endl;
				cout << "2) Modify costumer Details" << endl;
				cout << "3) Check Out Costumer" << endl;
				cout << "4) View Costumer List" << endl;
				cout << "Enter 9 to Exit" << endl;
				cin >> costumerS;
				clearScreen();
				if (costumerS == 1)
				{
					if (r.checkAvailableRooms())
					{
						string name;
						string CNIC;
						string contact;
						string address;
						int room;
						int floor;
						int day, month, year;
						cout << "Enter  Name" << endl;
						cin >> name;
						name = name;
						clearScreen();
						cout << "Enter  CNIC" << endl;
						cin >> CNIC;

						CNIC = CNIC;
						clearScreen();
						cout << "Enter  contact" << endl;
						cin >> contact;
						contact = contact;
						clearScreen();
						cout << "Enter  Address" << endl;
						cin.ignore();
						getline(cin, address);
						address = address;
						clearScreen();
						r.ViewAvailableRooms();
						cout << "Enter  Room No" << endl;
						cin >> room;
						room = room;
						cout << "Enter  Floor No" << endl;
						cin >> floor;
						floor = floor;
						clearScreen();
						cout << "Enter  Day" << endl;
						cin >> day;
						day = day;
						clearScreen();
						cout << "Enter  Month" << endl;
						cin >> month;
						month = month;
						clearScreen();
						cout << "Enter  Year" << endl;
						cin >> year;
						year = year;
						clearScreen();
						c.addCostumer(name, CNIC, contact, address, room, floor, day, month, year);
						r.availableRoom(to_string(room), to_string(floor));
						//c.display();
						clearScreen();
					}
					else
					{
						cout << "Free Rooms Are not Available" << endl;
						cin.ignore();
						waitForEnter();
					}
					break;
				}
				else if (costumerS == 2)
				{
					c.modifyCostumer();
					c.resaveData();
					clearScreen();
					break;
				}
				else if (costumerS == 3)
				{
					string name, CNIC;
					int Bill;
					int totalDaysSpent;
					c.display();

					cout << "\n\nEnter Name of the customer" << endl;
					cin >> name;
					cout << "Enter CNIC of the customer" << endl;
					cin >> CNIC;
					clearScreen();
					c.searchCustomer(name, CNIC, Bill, totalDaysSpent);
					cout << "\nYour Bill IS: " << Bill << endl;
					cout << "Your Days IS: " << totalDaysSpent << endl;
					cin.ignore();
					waitForEnter();
					clearScreen();

					c.removeCostumer(name, CNIC);
					c.resaveData();
					break;
				}
				else if (costumerS == 4)
				{
					c.display();
					cin.ignore();
					waitForEnter();
					clearScreen();
					break;
				}
				else if (costumerS == 9)
				{
					c.saveData();
					cin.ignore();
					waitForEnter();

					break;
				}
				break;
			}
			else if (m == 3)
			{
				while (History != 9)
				{
					cout << "================================" << endl;
					cout << "= Welcome to Costumer Services =" << endl;
					cout << "================================" << endl;
					cout << "1) View History" << endl;
					cout << "2) clear History" << endl;
					cout << "Enter 9 to Exit" << endl;
					cin >> History;
					clearScreen();
					h.loadDataFromFile(h);
					if (History == 1)
					{

						h.display();
						cin.ignore();
						waitForEnter();
						clearScreen();
					}
					else if (History == 2)
					{
						h.popAll();
					}
					else if (History == 9)
					{
						break;
					}
				}
				break;
			}
			else if (m == 9)
			{
				c.saveData();
				cin.ignore();
				waitForEnter();
				return 0;
				break;
			}
			else
			{
				cout << "Wrong Entry Press 'Enter' And Try Again" << endl;
				waitForEnter();
				clearScreen();
				break;
			}
		}
	}

	system("pause");
	return 0;
}
