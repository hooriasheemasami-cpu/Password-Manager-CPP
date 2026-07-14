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

void SavePassword(const string& site, const string& password) {
	ofstream file("passwords.txt", ios::app); // Open file in append mode, ofstream means output file stream, appending new information in the file
	if (file.is_open()) {
		file << site << " " << password << endl;
		file.close();
		displayMessage("Password saved successfully.");
	}
	else {
		cerr << "Error: Unable to open file for writing. \n";
	}
}

void LoadPasswords() {
	ifstream file("passwords.txt"); // ifstream means input file stream
	if (file.is_open()) {
		string site, password;
		displayMessage("\nSaved Passwords:");
		while (file >> site >> password) {
			cout << "Site: " << site << ", Password: " << password << endl;
		}
		file.close();
	}
	else {
		cerr << "\nError: [System] No passwords saved yet.\n";
	}
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
				displayMessage("Enter the site name: ");
				cin >> site;
				displayMessage("Enter the password: ");
				cin >> password;
				SavePassword(site, password);
				break;
			case 2:
				LoadPasswords();
				break;
			case 3:
				displayMessage("\n[System] Exiting... ");
				break;
			default:
				displayMessage("\n[System] Invalid choice. Please try again.");
				break;
		}
		 
	} while (choice != 3);

	return 0;
}