#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void saveUser(const string &username, const string &password) {
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << username << " " << password << endl;
        file.close();
    }
}


bool userExists(const string &username) {
    ifstream file("users.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (user == username) {
            return true;
        }
    }
    return false;
}


void registerUser() {
    string username, password;

    cout << "\n===== USER REGISTRATION =====\n";
    cout << "Enter a username: ";
    cin >> username;

    if (userExists(username)) {
        cout << "⚠️  Username already exists! Try another.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "⚠️  Invalid input! Username and password cannot be empty.\n";
        return;
    }

    saveUser(username, password);
    cout << "✅ Registration successful!\n";
}

bool verifyUser(const string &username, const string &password) {
    ifstream file("users.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (user == username && pass == password) {
            return true;
        }
    }
    return false;
}


void loginUser() {
    string username, password;

    cout << "\n===== USER LOGIN =====\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (verifyUser(username, password)) {
        cout << "✅ Login successful! Welcome, " << username << "!\n";
    } else {
        cout << "❌ Invalid username or password. Try again.\n";
    }
}

int getChoice() {
    int choice;
    while (true) {
        cout << "Enter your choice: ";
        if (cin >> choice && (choice == 1 || choice == 2 || choice == 3)) {
            return choice;
        } else {
            cout << "⚠️  Invalid input! Please enter 1, 2, or 3.\n";
            cin.clear(); 
            cin.ignore(10000, '\n'); 
        }
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== LOGIN & REGISTRATION SYSTEM =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        choice = getChoice(); 

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "👋 Exiting the program. Goodbye!\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
