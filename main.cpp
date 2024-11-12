#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> // For system commands

using namespace std;

bool isLoggedIn()
{
    string username, password;
    string un, pw; // comparison strings

    cout << "Enter a username: ";
    cin >> username;
    cout << "Enter a password: ";
    cin >> password;

    ifstream read(username + ".txt"); // ifstream reads a file 

    if (read.is_open())
    {
        getline(read, un); // reads the username 
        getline(read, pw); // reads the password
    }
    else
    {
        cout << "User not found." << endl;
        return false;
    }

    if(un == username && pw == password) // if both un & username and pw & password are the same, true
    {
        return true;
    }
    else
    {
        return false;
    }
}

void registerUser()
{
    string username, password;

    cout << "Registration: " << endl;
    cout << "Select a username: "; 
    cin >> username;
    cout << "Select a password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl << password;
    file.close();
    cout << "Registration successful. Welcome, " << username << "!" << endl;
}

void displayDashboard()
{
    cout << "Successfully logged in!" << endl;
    cout << endl;

    cout << "Welcome back!" << endl;
    cout << "DASHBOARD" << endl;
    cout << "No new messages." << endl;
    cout << endl;
}

int main()
{
    int choice;

    while (true) 
    {
        cout << endl;
        cout << "Main Menu: " << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            if (isLoggedIn())
            {
                displayDashboard();
            }
            else
            {
                cout << "Invalid login!" << endl;
            }
        }
        else if (choice == 3)
        {
            cout << "Exiting program..." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
