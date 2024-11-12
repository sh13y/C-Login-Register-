# Simple Login and Registration System in C++

This is a basic C++ program that implements a login and registration system using text files to store and verify user credentials.

## How It Works

The program allows users to register with a username and password or log in with an existing account. Each username is stored in a separate text file, where the username and password are saved. Here’s a breakdown of the main features:

### Features

1. **Main Menu**: Users can select from two options:
   - Register a new account
   - Log in to an existing account

2. **Registration**:
   - Prompts the user for a username and password.
   - Creates a text file named `<username>.txt` and stores the username and password inside.
   
3. **Login**:
   - Prompts the user to enter their username and password.
   - Reads the corresponding text file and verifies if the entered credentials match the stored ones.

4. **Dashboard**:
   - After a successful login, a simple dashboard is displayed with two options:
     - **Sign Out**: Exits the program.
     - **Back to Main Menu**: Returns to the main menu, allowing the user to register or log in again.

### Code Explanation

1. **isLoggedIn() Function**: 
   - Takes a username and password as input.
   - Reads the stored username and password from the text file named `<username>.txt`.
   - Returns `true` if the input matches the stored credentials; otherwise, it returns `false`.

2. **main() Function**:
   - Displays the main menu and handles user input for registration and login.
   - If registration is selected, it prompts for a username and password, then saves them in a new text file.
   - If login is selected, it calls the `isLoggedIn()` function to verify credentials.
   - Upon successful login, a simple dashboard is displayed.

## Code Sample

```cpp
#include <iostream> 
#include <fstream> // reading and writing files 
#include <string>

using namespace std;

// Function for logging in
bool isLoggedIn()
{
    string username, password;
    string un, pw; // comparison strings

    cout << "Enter a username: ";
    cin >> username; 
    cout << "Enter a password: ";
    cin >> password;

    ifstream read(username + ".txt"); // ifstream reads a file 
    getline(read, un); // reads the username 
    getline(read, pw); // reads the password

    return un == username && pw == password;
}

// Main function handling the main menu, registration, and login
int main()
{
    int choice;
    cout << "Main Menu:\n1. Register\n2. Login\nYour choice: ";
    cin >> choice;

    if(choice == 1)
    {
        // Registration
        string username, password;
        cout << "Registration:\nSelect a username: ";
        cin >> username;
        cout << "Select a password: ";
        cin >> password;

        ofstream file(username + ".txt"); 
        file << username << endl << password;
        file.close();
        cout << "Welcome " << username << "!" << endl;
    }
    else if(choice == 2)
    {
        // Login
        if(isLoggedIn())
        {
            cout << "Successfully logged in!\nDASHBOARD\n1. Sign Out\n2. Back to main menu\nYour choice: ";
            int choiceTwo;
            cin >> choiceTwo;

            if(choiceTwo == 1)
            {
                system("exit");
            }
            else if(choiceTwo == 2)
            {
                main();
            }
        }
        else
        {
            cout << "Invalid login!\n";
            main();
        }
    }
    return 0;
}
