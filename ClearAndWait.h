#pragma once
#include<iostream>
using namespace std;
void clearScreen() {
#ifdef _WIN32
	system("cls"); // For Windows
#endif
}
void waitForEnter() {
	//cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cin.get();
}