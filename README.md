# C++ Login and Registration System

This program implements a simple login and registration system using C++ and text files to store user credentials. Users can register an account, log in, and view a basic dashboard upon successful login. Key improvements were made for enhanced usability and better code organization.

## Key Features

- **Main Menu**: Users can choose to register a new account, log in to an existing account, or exit the program.
- **Registration**: Prompts the user to enter a unique username and password. Credentials are stored in a text file named `<username>.txt`.
- **Login**: Validates user credentials by checking against the stored username and password.
- **Dashboard**: Upon successful login, a simple dashboard is displayed, welcoming the user.
- **Error Handling**: Displays a message if the user file does not exist or if credentials are incorrect.

## Key Changes and Improvements

1. **Function Organization**: The code is modularized with `registerUser()`, `isLoggedIn()`, and `displayDashboard()` functions, making it easier to understand and maintain.
2. **Error Handling**:
   - Checks if the user file exists during login. Displays "User not found" if the file is missing.
   - Added validation for incorrect menu choices to improve user guidance.
3. **Looping Menu**: The `while(true)` loop allows users to return to the main menu after each action, creating a smoother user experience.
4. **Exit Option**: A "3. Exit" option was added to allow users to exit the program gracefully.

## Code Overview

1. **isLoggedIn()**:
   - Takes a username and password as input.
   - Checks if the user file `<username>.txt` exists.
   - If the file exists, it reads the credentials and compares them to the input values.
   - Returns `true` if credentials match, otherwise returns `false`.

2. **registerUser()**:
   - Prompts the user to create a username and password.
   - Saves credentials to a new file named `<username>.txt`.
   - Displays a message confirming successful registration.

3. **displayDashboard()**:
   - Shows a basic welcome message upon successful login.

4. **main()**:
   - Displays the main menu and prompts the user to choose an action.
   - Calls appropriate functions based on the user's choice.
   - Includes input validation to handle invalid choices and exits if the user selects "3. Exit."

## Future Improvements

- **Password Encryption**: Encrypt passwords before saving them to enhance security.
- **Multiple Attempts Limit**: Restrict login attempts to prevent brute-force attacks.
- **Password Requirements**: Enforce minimum length or complexity for passwords.
- **Account Recovery**: Add functionality for users to recover or reset their passwords.
- **Database Integration**: Use a database for credential storage, making the system scalable and more secure.

## How to Compile and Run

1. Clone or download this repository.
2. Compile the code:
   ```bash
   g++ -o login_system login_system.cpp
