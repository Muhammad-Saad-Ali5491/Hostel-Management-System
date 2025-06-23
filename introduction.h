#pragma once
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void intro()
{
	ifstream inputFile("introduction.txt");

	// Check if the file is open successfully
	if (!inputFile.is_open()) {
		cerr << "Error opening the file!" << endl;
		// Return an error code
	}

	// Read the file line by line
	string line;
	while (getline(inputFile, line)) {
		// Process each line as needed
		cout << line << endl;
	}

	// Close the file
	inputFile.close();
	cout << "\t\t\t\t\t Press 'Enter' to Continue\n";
}
