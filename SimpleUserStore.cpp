#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
* 
* Project 'User Dictionary'
* 
* This projects allows users to select two options, one rather to
* create a new account stored locally or login to a account stored locally.
* 
* Zero encryption for passwords as we are locally hosted.
* 
*/
bool isUserLoggedIn() {

	string username, password, un, pw; // declare our local variables; username, password being inputs and un, pw being used to validate the inputs.

	cout << "Enter username: ";
	cin >> username; // ask for username input

	cout << "Enter password: ";
	cin >> password; // ask for password input

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw); // read our 'database' and store these found variables in un and pw.

	return un == username && pw == password; // validate our inputs with our stored data
}

int main() {

	int selectedChoice;

	cout << "\n";
	cout << "Enter your choice, ";
	cout << "\n";
	cout << "1: Register Account\n"; // show our options to the console
	cout << "2: Login to your Account";
	cout << "\n";

	cout << "Enter selection: ";

	cin >> selectedChoice;


	switch (selectedChoice) {
		case 1: { // if selected to register a account
			string username, password;

			cout << "Select a username: "; // ask for username
			cin >> username;

			cout << "Select a password: "; // ask for password
			cin >> password;

			ofstream file;

			file.open(username + ".txt");
			file << username << endl << password; // write to a new file called '<username>.txt' the username and password.
			file.close();

			main();
			break;
		}
		case 2: { // if selected to login
			if (!isUserLoggedIn()) { // validate given inputs 
				cout << "Invalid login! " << endl; // if doesn't exist or not valid prompt
				system("PAUSE");

				return 0;
			}

			cout << "Successfully logged in!"; // if successful prints that it was successful.
			system("PAUSE");
			return 1;
		}
		default: {
			cout << "Please enter a valid choice.";
			break;
		}
	}

}
