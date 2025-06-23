#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"ClearAndWait.h"
using namespace std;
void menu()
{
	ifstream inputFile("menu.txt");

	// Check if the file is open successfully
	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
	}

	// Read the file line by line
	string line1;
	while (getline(inputFile, line1)) {
		// Process each line as needed
		cout << line1 << endl;
	}

	// Close the file
	inputFile.close();

	cout << "Choose from the options below:" << endl;
	cout << "1) Sign Up" << endl;
	cout << "2) Login user" << endl;
}
void signup()
{
	ofstream fout("Login_IDs.txt", ios::app);
	if (!fout)
	{
		cout << "error in reading file" << endl;
		return;
	}
	string account;
	string password, check;
	cout << "Enter Account/Email ID" << endl;
	cin >> account;
	cout << "Enter Password" << endl;
	cin >> password;
	cout << "confirm Password" << endl;
	cin >> check;
	if (password == check)
	{
		fout << account << "-" << password << endl;
	}
	else
	{
		cout << "Wrong Entry Press 'Enter' Try Again" << endl;
		waitForEnter();

		clearScreen();
		signup();
	}

	fout.close();
}
bool login()
{
	string account, checka;
	string password, checkp;
	bool found = false;

	cout << "Enter Account/Email ID" << endl;
	cin >> account;
	cout << "Enter Password" << endl;
	cin >> password;

	ifstream fin("Login_IDs.txt");
	if (!fin.is_open())
	{
		cout << "file not found" << endl;
		waitForEnter();
	}
	while (getline(fin, checka, '-') && getline(fin, checkp, '\n'))
	{
		// Check if the entered account and password match
		if (account == checka && password == checkp)
		{
			cout << "Sign-in successful!" << endl;
			cin.ignore();
			waitForEnter();
			found = true;
			return found;
		}
	}
	if (!found)
	{
		cout << "Invalid account or password. Sign-in failed. try again" << endl;
		login();
		//return false;
	}
	fin.close();
}
