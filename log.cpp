#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a user
void registerUser() {
    string username, password;
    cout << "Register a new user\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open a file to store user credentials
    ofstream file;
    file.open("database.txt", ios::app);  // Append mode
    if (file.is_open()) {
        file << username << " " << password << endl;
        cout << "User registered successfully!\n";
        file.close();
    } else {
        cout << "Error opening the file!\n";
    }
}

// Function to check if login is successful
bool loginUser() {
    string username, password, user, pass;
    cout << "Login\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Open the file to read stored credentials
    ifstream file;
    file.open("database.txt");
    if (file.is_open()) {
        while (file >> user >> pass) {
            if (user == username && pass == password) {
                cout << "Login successful!\n";
                return true;
            }
        }
        file.close();
    } else {
        cout << "Error opening the file!\n";
    }
    cout << "Invalid username or password!\n";
    return false;
}

int main() {
    int choice;
    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) {
                    // If login is successful, we can add more features here
                    cout << "Welcome to the system!\n";
                }
                break;
            case 3:
                cout << "Exiting...\n";
                exit(0);
                break;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    }
    return 0;
}
