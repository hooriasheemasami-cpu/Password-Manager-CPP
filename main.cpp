#include <iostream>
using namespace std;
#include <fstream> // For file handling 
#include <limits>

void displayMessage(const string& message) {
	cout << message << endl;
}

void displayMenu() {
	cout << "Password Manager Menu:" << endl;
	cout << "1. Add a new password" << endl;
	cout << "2. View saved passwords" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter your choice: ";
}

int main() {
	int choice;
	string site, password;

	do {
		displayMenu();
		cin >> choice;
		if (cin.fail()) {
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
			displayMessage("Invalid input. Please enter a number between 1 and 3.");
			continue;
		}

		switch (choice) {
			case 1:

				break;
			case 2:

				break;
			case 3:

				break;
			default:

				break;
		}
		 
	} while (choice != 3);

	return 0;
}