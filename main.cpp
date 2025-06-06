#include<iostream> // Include standard input-output stream for console input/output operations

#include<fstream> // Include fstream for file handling (read/write operations on files)

#include<string> // Include string library for handling strings

#include<iomanip> // Include iomanip for setting input/output formatting (e.g., setw, precision)

#include<conio.h> // Include conio for console input/output operations (like getch, clrscr for Windows)

using namespace std;  // Use the standard namespace to avoid prefixing 'std::' before standard functions

// ANSI color codes for resetting text color/style
#define RESET   "\033[0m"

// Define ANSI color codes for various colors
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Bright color codes for lighter shades of the standard colors
#define BRIGHT_BLACK   "\033[1;30m"
#define BRIGHT_RED     "\033[1;31m"
#define BRIGHT_GREEN   "\033[1;32m"
#define BRIGHT_YELLOW  "\033[1;33m"
#define BRIGHT_BLUE    "\033[1;34m"
#define BRIGHT_MAGENTA "\033[1;35m"
#define BRIGHT_CYAN    "\033[1;36m"
#define BRIGHT_WHITE   "\033[1;37m"

// Background color codes to change the background color of text
#define BG_BLACK   "\033[40m"
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN    "\033[46m"
#define BG_WHITE   "\033[47m"

// 'head' function displays the header of the hotel management system
void head() {
    // Clear the console screen (CLS is for Windows, change to "clear" for Unix-based OS)
    system("CLS");
    
    // Set text color to bright cyan and background to black
    cout << BRIGHT_CYAN << BG_BLACK;
    
    // Print the first line of the border with a mix of dashes to create separation
    cout << "-------------------------------------------";
    cout << "--------------------------------------------" << RESET << endl;
    
    // Print the name of the hotel in the center
    cout << BRIGHT_CYAN << BG_BLACK << "\t\t\t----THE GRAND SAPPHIRE HOTEL----" << RESET << endl;
    
    // Print the second border line below the hotel name
    cout << BRIGHT_CYAN << BG_BLACK << "\t-------------------------------------------";
    cout << "--------------------------------------------" << RESET << endl;
}

// Define the class 'SAPPHIRE_HOTEL' to represent the hotel booking system
class SAPPHIRE_HOTEL {
private:
    // Private member variables to store customer and room details
    int room_no;                // Room number
    char name[30];              // Customer's name
    char address[50];           // Customer's address
    char phone[15];             // Customer's phone number
    int days;                   // Number of days the customer will stay
    float fare;                 // Total fare for the stay
    float extraServices;        // Charges for extra services
    float discount;             // Discount applied

    // Private member functions for meal options in the restaurant
    void breakfast();
    void lunch();
    void dinner();

public:
    // Public member functions for various features of the hotel system
    void main_menu();           // Displays the main menu
    void add();                 // Adds a new booking
    void display();             // Displays customer details
    void rooms();               // Displays available rooms
    void edit();                // Edits customer details
    int check(int);             // Checks room availability
    void modify();              // Modifies a booking
    void delete_rec();          // Deletes a booking
    void restaurant();          // Handles restaurant services
    void applyDiscount();       // Applies discount to the bill
    void generateReport();      // Generates a report of customer activities
    void feedback();            // Collects feedback from customers
    void printInvoice();        // Prints the invoice after checkout
    bool login();               // Handles staff login

};

// Function to handle staff login
bool SAPPHIRE_HOTEL::login() {
    string username, password;            // Variables to store entered username and password
    string stored_username = "admin";     // Predefined valid username
    string stored_password = "sapphire123"; // Predefined valid password

    // Display login header with ANSI colors
    cout << BRIGHT_BLUE << BG_BLACK << "\t\t\t-------------------------------------------------------------------" << RESET << endl;
    cout << BRIGHT_BLUE << BG_BLACK << "\t\t\t\t--------- THE GRAND SAPPHIRE HOTEL STAFF LOGIN ------" << RESET << endl;
    cout << BRIGHT_BLUE << BG_BLACK << "\t\t\t\t--------- Please Enter Your Credentials Below -------" << RESET << endl;
    cout << BRIGHT_BLUE << BG_BLACK << "\t\t\t-------------------------------------------------------------------" << RESET << endl;
    
    // Prompt user for username
    cout << "\n " << BRIGHT_WHITE << " Enter Username: " << RESET;
    cin >> username;                      // Get the username input

    // Prompt user for password (input will be masked with '*')
    cout << " " << BRIGHT_WHITE << " Enter Password: " << RESET;
    char ch;                              // Variable to store each character of the password
    ch = _getch();                        // Use _getch() to capture input without displaying it

    // Loop to get password input and mask it with '*' characters
    while (ch != 13) {                    // Loop until the 'Enter' key (ASCII code 13) is pressed
        if (ch == 8) {                    // If backspace (ASCII code 8) is pressed
            if (!password.empty()) {      // Check if password is not empty
                password.pop_back();      // Remove the last character from the password
                cout << "\b \b";          // Move cursor back and overwrite with space
            }
        } else {
            password.push_back(ch);       // Add the entered character to the password
            cout << '*';                  // Display '*' to mask the password
        }
        ch = _getch();                    // Get the next character
    }

    // Check if the entered username and password match the stored credentials
    if (username == stored_username && password == stored_password) {
        cout << endl << BRIGHT_GREEN << "\n Login Successful! Press any key to continue...." << RESET << endl;
        _getch();                         // Wait for any key press to continue
        return true;                      // Return true if login is successful
    } else {
        cout << endl << BRIGHT_RED << "\n Invalid Credentials! Try again." << RESET << endl;
        return false;                     // Return false if login fails
    }
}

// Function to get valid menu input from the user
char getValidInput(bool &showInvalidMsg) {
    string input;                         // String to store the user's input

    // If invalid input message flag is set, show an error message
    if (showInvalidMsg) {
        // Show error message (optional code to display invalid input message can be added here)
        showInvalidMsg = false;           // Reset the flag after showing the message
    }

    // Prompt the user for their choice
    cout << "\n\n\t\t\t" << BRIGHT_WHITE << "Enter Your Choice: " << RESET;
    cin >> input;                         // Get the input as a string

    // Check if the input length is 1 and if it is a valid digit between '1' and '9'
    if (input.length() == 1 && isdigit(input[0]) && input[0] >= '1' && input[0] <= '9') {
        return input[0];                  // Return the valid input character
    } else {
        showInvalidMsg = true;            // Set the flag to display the invalid input message
        return '\0';                      // Return null character for invalid input
    }
}

// Member function to display the main menu and handle user interactions
void SAPPHIRE_HOTEL::main_menu() {
    char choice;                         // Variable to store the user's menu choice
    bool showInvalidMsg = false;         // Flag to indicate if an invalid input message should be displayed

    do {
        system("CLS");                   // Clear the screen for a fresh display of the menu
        head();                          // Call the header function to display the hotel name and banner

        // Check if the previous input was invalid, and show an error message if necessary
        if (showInvalidMsg) {
            cout << BRIGHT_RED << "\n\n\t\t\tInvalid input! Please enter a valid choice (1-9)." << RESET;
        }

        // Display the main menu with decorative lines and options using ANSI colors
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "***********************************" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*         HOTEL MAIN MENU         *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "***********************************" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [1] Book A Room                *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [2] Customer Information       *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [3] Rooms Allotted             *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [4] Edit Customer Details      *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [5] Order Food from Restaurant *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [6] Check Out and Print Bill   *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [7] Feedback                   *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [8] Generate Report            *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "*  [9] Exit                       *" << RESET;
        cout << "\n\t\t\t" << BRIGHT_YELLOW << BG_BLACK << "***********************************" << RESET << "\n";

        // Get the user's choice, while checking for valid input using the getValidInput function
        choice = getValidInput(showInvalidMsg);
        if (choice == '\0') {            // If input is invalid, skip the switch-case and repeat the loop
            continue;                    // Re-display the menu without executing the switch block
        }

        // Handle the user's choice based on the input
        switch (choice) {
            case '1':
                add();                   // Call the add function to book a room
                break;

            case '2':
                display();               // Call the display function to show customer information
                break;

            case '3':
                rooms();                 // Call the rooms function to display allotted rooms
                break;

            case '4':
                edit();                  // Call the edit function to modify customer details
                break;

            case '5':
                restaurant();            // Call the restaurant function to order food
                break;

            case '6':
                printInvoice();          // Call the printInvoice function to check out and print the bill
                break;

            case '7':
                feedback();              // Call the feedback function to collect customer feedback
                break;

            case '8':
                generateReport();        // Call the generateReport function to generate a report
                break;

            case '9':
                return;                  // Exit the menu and return to the previous context
              
            default:
                showInvalidMsg = true;   // This case should not be reached due to validation, but flag invalid input
                break;
        }
    } while (true);                      // Repeat the menu display and handling until '9' (Exit) is chosen
}

void SAPPHIRE_HOTEL::add() {
    // Clear the console screen
    system("CLS");
    // Display the header information (presumably a hotel title or logo)
    head();

    int r, flag;  // Declare room number (r) and a flag to check room availability
    // Open a file named "Record.txt" in append mode to save customer details
    ofstream fout("Record.txt", ios::app);

    // Output prompt to enter customer details with styled text
    cout << BRIGHT_BLUE << BG_BLACK << "\n Enter Customer Details " << RESET;
    cout << "\n ----------------------" << RESET;

    string str;  // Temporary string to hold user input for room number
    int num = 0; // Variable to store the converted room number
    bool isInteger = false; // Flag to check if the input is a valid integer

    // Loop until a valid integer is entered for the room number
    while (!isInteger) {
        cout << "\n\n " << BRIGHT_WHITE << "Room Number:" << RESET; // Prompt for room number
        cin >> str; // Read input into the string

        // Try to convert the string to an integer
        try {
            num = stoi(str); // Convert string to integer
            isInteger = true; // Set flag to true if conversion is successful
        } catch (const invalid_argument& e) {
            // If conversion fails, output an error message
            cerr << "Error: You have given a String  ";
        }
    }

    r = num; // Assign the validated room number to the variable r
    flag = check(r); // Check if the room is already booked

    // If the room is booked, inform the user
    if (flag) {
        cout <<  BRIGHT_RED << BG_BLACK << "\n Sorry, Room is already booked." << RESET;
    } else {
        room_no = r; // If available, set the room number for the booking
        cout << " " << BRIGHT_WHITE << "Name: " << RESET; // Prompt for customer name
        cin.ignore(); // Clear the input buffer
        cin.getline(name, 30); // Read the customer's name

        cout << " " << BRIGHT_WHITE << "Address: " << RESET; // Prompt for customer address
        cin.getline(address, 50); // Read the customer's address

        cout << " " << BRIGHT_WHITE << "Phone Number: " << RESET; // Prompt for phone number
        cin.getline(phone, 15); // Read the customer's phone number

        cout << " " << BRIGHT_WHITE << "Number of Days: " << RESET; // Prompt for number of days
        cin >> days; // Read the number of days for the stay

        fare = days * 900; // Calculate fare based on the number of days
        extraServices = 0.0; // Initialize extra services charge

        applyDiscount(); // Apply any discounts if applicable

        // Write customer details to the file
        fout << room_no << endl; // Write room number
        fout << name << endl; // Write customer name
        fout << address << endl; // Write customer address
        fout << phone << endl; // Write customer phone number
        fout << days << endl; // Write number of days
        fout << fare << endl; // Write calculated fare
        fout << extraServices << endl; // Write extra services charge
        fout << discount << endl; // Write discount applied

        // Inform the user that the room has been successfully booked
        cout <<  BRIGHT_GREEN << BG_BLACK << "\n Room has been booked." << RESET;
    }

    cout << "\n Press any key to continue."; // Prompt to continue
    getch(); // Wait for user input

    fout.close(); // Close the output file
}

void SAPPHIRE_HOTEL::display() {
    // Clear the console screen
    system("CLS");
    // Display the header information (presumably a hotel title or logo)
    head();

    // Open the file "Record.txt" in read mode to access customer records
    ifstream fin("Record.txt");

    int r; // Variable to store the room number input by the user
    int flag = 0; // Flag to indicate if the room was found (0 means not found)

    // Prompt the user to enter a room number to display details
    cout << BRIGHT_BLUE << BG_BLACK << "\n Enter Room Number:" << RESET;
    cin >> r; // Read the room number from user input

    // Read customer records from the file until the end of the file is reached
    while (fin >> room_no) {
        fin.ignore(); // Ignore the newline character after reading room_no
        fin.getline(name, 30); // Read customer name from the file
        fin.getline(address, 50); // Read customer address from the file
        fin.getline(phone, 15); // Read customer phone number from the file
        fin >> days >> fare >> extraServices >> discount; // Read additional details
        fin.ignore(); // Ignore the newline character after reading the last field

        // Check if the current room number matches the user's input
        if (room_no == r) {
            // Clear the screen and display the header again
            system("CLS");
            head();

            // Output customer details with styled text
            cout << BRIGHT_MAGENTA << BG_BLACK;
            cout << "\n Customer Details ";
            cout << "\n ---------------- " << RESET;

            cout << "\n\n " << BRIGHT_WHITE << "Room Number: " << room_no; // Display room number
            cout << "\n " << BRIGHT_WHITE << "Name: " << name; // Display customer name
            cout << "\n " << BRIGHT_WHITE << "Address: " << address; // Display customer address
            cout << "\n " << BRIGHT_WHITE << "Phone Number: " << phone; // Display customer phone number
            cout << "\n " << BRIGHT_WHITE << "Staying for " << days << " days."; // Display stay duration
            cout << "\n " << BRIGHT_WHITE << "Extra Services Charges: Rs " << extraServices; // Display extra services charges
            cout << "\n " << BRIGHT_WHITE << "Total Fare: Rs " << fare - discount + extraServices; // Display total fare calculation

            flag = 1; // Set flag to indicate that the room was found
            break; // Exit the loop since the room has been found
        }
    }

    // If no matching room was found, display a not found message
    if (flag == 0) {
        cout << BRIGHT_RED << BG_BLACK << "\n Room not found." << RESET;
    }

    cout << "\n\n Press any key to continue."; // Prompt to continue
    getch(); // Wait for user input

    fin.close(); // Close the input file
}

void SAPPHIRE_HOTEL::rooms() {
    // Clear the console screen
    system("CLS");
    // Display the header information (presumably a hotel title or logo)
    head();

    // Open the file "Record.txt" in read mode to access customer records
    ifstream fin("Record.txt");

    // Display a styled title for the list of allotted rooms
    cout << BRIGHT_YELLOW << BG_BLACK;
    cout << "\n\t\t\t    List Of Rooms Allotted";
    cout << "\n\t\t\t    -----------------------" << RESET;

    // Read customer records from the file until the end of the file is reached
    while (fin >> room_no) {
        fin.ignore(); // Ignore the newline character after reading room_no
        fin.getline(name, 30); // Read customer name from the file
        fin.getline(address, 50); // Read customer address from the file
        fin.getline(phone, 15); // Read customer phone number from the file
        fin >> days >> fare >> extraServices >> discount; // Read additional details
        fin.ignore(); // Ignore the newline character after reading the last field

        // Output customer details with styled text
        cout << "\n " << BRIGHT_WHITE << "Room Number: " << room_no;
        cout << "\n " << BRIGHT_WHITE << "Name: " << name;
        cout << "\n " << BRIGHT_WHITE << "Address: " << address;
        cout << "\n " << BRIGHT_WHITE << "Phone: " << phone;
        cout << "\n " << BRIGHT_WHITE << "Days: " << days;
        cout << "\n " << BRIGHT_WHITE << "Extra Services Charges: Rs " << extraServices;
        cout << "\n " << BRIGHT_WHITE << "Total Fare: Rs " << fare - discount + extraServices;
        cout << "\n**********************************"; // Separator for each customer
    }

    // Prompt to continue after displaying the list
    cout << "\n\n\t\t\tPress any key to continue.";
    getch(); // Wait for user input

    fin.close(); // Close the input file
}

void SAPPHIRE_HOTEL::edit() {
    // Clear the console screen
    system("CLS");
    // Display the header information
    head();

    int choice, r; // Declare variables for user choice and room number

    // Display an edit menu title
    cout << BRIGHT_BLUE << BG_BLACK << "\n EDIT MENU";
    cout << "\n ---------" << RESET;
    cout << "\n\n " << BRIGHT_WHITE << "1. Modify Customer Information."; // Option to modify info
    cout << "\n " << BRIGHT_WHITE << "2. Customer Check Out."; // Option for checkout

    // Prompt the user for their choice
    cout << "\n " << BRIGHT_WHITE << "Enter your choice: " << RESET;
    cin >> choice; // Read the user's choice

    system("CLS"); // Clear the screen again
    head(); // Display the header again

    // Prompt for the room number to edit
    cout << "\n " << BRIGHT_WHITE << "Enter Room Number: " << RESET;
    cin >> r; // Read the room number

    // Switch statement to handle different edit options
    switch (choice) {
        case 1: // Modify customer information
            room_no = r; // Set the room number for modification
            modify(); // Call the modify function to update information
            break;
        case 2: // Customer checkout
            delete_rec(); // Call the function to delete the record
            break;
        default: // Handle invalid choice
            cout << BRIGHT_RED << BG_BLACK << "\n Wrong Choice." << RESET;
    }

    // Prompt to continue after editing
    cout << "\n Press any key to continue.";
    getch(); // Wait for user input
}

int SAPPHIRE_HOTEL::check(int r) {
    int flag = 0; // Initialize a flag to indicate if the room is found

    // Open the file "Record.txt" in read mode to access customer records
    ifstream fin("Record.txt");

    // Read customer records from the file until the end of the file is reached
    while (fin >> room_no) {
        fin.ignore(); // Ignore the newline character after reading room_no
        fin.getline(name, 30); // Read customer name from the file
        fin.getline(address, 50); // Read customer address from the file
        fin.getline(phone, 15); // Read customer phone number from the file
        fin >> days >> fare >> extraServices >> discount; // Read additional details
        fin.ignore(); // Ignore the newline character after reading the last field

        // Check if the current room number matches the provided room number
        if (room_no == r) {
            flag = 1; // Set flag to indicate that the room was found
            break; // Exit the loop since the room has been found
        }
    }

    fin.close(); // Close the input file
    return flag; // Return the flag indicating room availability (1 if found, 0 if not)
}

void SAPPHIRE_HOTEL::modify() {
    // Open the file "Record.txt" in read and write mode, with the file pointer positioned at the end
    fstream file("Record.txt", ios::in | ios::out | ios::ate);

    // Move the file pointer back to the beginning of the file
    file.seekg(0);

    long pos; // Variable to store the position of the current record in the file
    int flag = 0; // Flag to indicate if the room was found and modified

    // Read customer records from the file until the end of the file is reached
    while (file >> room_no) {
        pos = file.tellg(); // Store the current position of the file pointer
        file.ignore(); // Ignore the newline character after reading room_no
        file.getline(name, 30); // Read customer name from the file
        file.getline(address, 50); // Read customer address from the file
        file.getline(phone, 15); // Read customer phone number from the file
        file >> days >> fare >> extraServices >> discount; // Read additional details
        file.ignore(); // Ignore the newline character after reading the last field

        // Check if the current room number matches the room number to be modified
        if (room_no == this->room_no) {
            // Clear the screen and display the header information
            system("CLS");
            head();

            // Prompt the user to enter new customer details
            cout << BRIGHT_BLUE << BG_BLACK << "\n Enter New Details ";
            cout << "\n ----------------- " << RESET;
            cout << " " << BRIGHT_WHITE << "\n\nName: " << RESET;
            cin.ignore(); // Ignore any leftover newline character in the input buffer
            cin.getline(name, 30); // Read new customer name

            cout << " " << BRIGHT_WHITE << "Address: " << RESET;
            cin.getline(address, 50); // Read new customer address

            cout << " " << BRIGHT_WHITE << "Phone Number: " << RESET;
            cin.getline(phone, 15); // Read new customer phone number

            cout << " " << BRIGHT_WHITE << "Number of Days: " << RESET;
            cin >> days; // Read new number of days for the stay

            fare = days * 900; // Calculate new fare based on the number of days

            applyDiscount(); // Apply any applicable discounts

            // Move the file pointer back to the position of the current record for updating
            file.seekp(pos - static_cast<long>(sizeof(room_no)));

            // Write the updated customer details back to the file
            file << room_no << endl;
            file << name << endl;
            file << address << endl;
            file << phone << endl;
            file << days << endl;
            file << fare << endl;
            file << extraServices << endl;
            file << discount << endl;

            // Confirm that the record has been modified
            cout << BRIGHT_GREEN << BG_BLACK << "\n Record Modified." << RESET;
            flag = 1; // Set flag to indicate that the record was successfully modified
            break; // Exit the loop since the record has been modified
        }
    }

    // If no matching room was found, display a not found message
    if (flag == 0) {
        cout << BRIGHT_RED << BG_BLACK << "\n Room not found." << RESET;
    }

    // Prompt to continue after modifying
    cout << "\n\n Press any key to continue.";
    getch(); // Wait for user input

    file.close(); // Close the file after finishing the modifications
}

void SAPPHIRE_HOTEL::delete_rec() {
    // Clear the screen and display the header
    system("CLS");
    head();

    int r; // Variable to store the room number to be deleted
    int flag = 0; // Flag to check if the room was found and deleted

    cout << BRIGHT_WHITE << "Enter Room Number: " << RESET; // Prompt for room number
    cin >> r; // Read room number from user input

    // Open the records file for reading and a temporary file for writing
    ifstream fin("Record.txt");
    ofstream fout("Temp.txt");

    // Read each record from the file
    while (fin >> room_no) {
        fin.ignore(); // Ignore newline character after room number
        fin.getline(name, 30); // Read customer name
        fin.getline(address, 50); // Read customer address
        fin.getline(phone, 15); // Read customer phone number
        fin >> days >> fare >> extraServices >> discount; // Read other details
        fin.ignore(); // Ignore newline character after last detail

        // If the current room number matches the room to be deleted
        if (room_no == r) {
            cout << BRIGHT_GREEN << BG_BLACK << "\n Room Deleted." << RESET; // Notify deletion
            flag = 1; // Set flag to indicate room was found
        } else {
            // Write the record to the temporary file since it’s not deleted
            fout << room_no << endl;
            fout << name << endl;
            fout << address << endl;
            fout << phone << endl;
            fout << days << endl;
            fout << fare << endl;
            fout << extraServices << endl;
            fout << discount << endl;
        }
    }

    // If no matching room was found, display a not found message
    if (flag == 0) {
        cout << BRIGHT_RED << BG_BLACK << "\n Room not found." << RESET;
    }

    cout << "\n\n Press any key to continue."; // Prompt to continue
    getch(); // Wait for user input

    fin.close(); // Close the input file
    fout.close(); // Close the output file

    // Remove the original records file and rename the temporary file to the original file name
    remove("Record.txt");
    rename("Temp.txt", "Record.txt");
}

void SAPPHIRE_HOTEL::breakfast() {
    extraServices += 200; // Add breakfast charge to extra services
}

void SAPPHIRE_HOTEL::lunch() {
    extraServices += 500; // Add lunch charge to extra services
}

void SAPPHIRE_HOTEL::dinner() {
    extraServices += 700; // Add dinner charge to extra services
}

void SAPPHIRE_HOTEL::restaurant() {
    int choice; // Variable to store the user's choice for meal type

    // Clear the screen and display the header
    system("CLS");
    head();

    // Display restaurant menu options
    cout << BRIGHT_YELLOW << BG_BLACK;
    cout << "\n\t\t\t\t**************";
    cout << "\n\t\t\t\t* RESTAURANT *";
    cout << "\n\t\t\t\t**************" << RESET;

    // Display meal options with prices
    cout << "\n\n\n\t\t\t" << BRIGHT_WHITE << BG_BLACK << "1. Breakfast (Rs 200/-)" << RESET;
    cout << "\n\t\t\t" << BRIGHT_WHITE << BG_BLACK << "2. Lunch (Rs 500/-)" << RESET;
    cout << "\n\t\t\t" << BRIGHT_WHITE << BG_BLACK << "3. Dinner (Rs 700/-)" << RESET;

    cout << "\n\n\t\t\t" << BRIGHT_WHITE << "Enter Your Choice: " << RESET; // Prompt for meal choice
    cin >> choice; // Read user's choice

    float additionalCharge = 0.0; // Variable to store additional charge based on meal choice

    // Set additional charge based on user's choice
    switch (choice) {
        case 1:
            additionalCharge = 200; // Breakfast charge
            break;
        case 2:
            additionalCharge = 500; // Lunch charge
            break;
        case 3:
            additionalCharge = 700; // Dinner charge
            break;
        default:
            cout << BRIGHT_RED << BG_BLACK << "\n Wrong choice." << RESET; // Handle invalid choice
            return; // Exit the function
    }

    int r; // Variable to store room number for which services are added
    cout << "\n " << BRIGHT_WHITE << "Enter Room Number: " << RESET; // Prompt for room number
    cin >> r; // Read room number

    // Open the records file for reading and a temporary file for writing
    ifstream fin("Record.txt");
    ofstream fout("Temp.txt");

    bool roomFound = false; // Flag to check if the room was found

    // Read each record from the file
    while (fin >> room_no) {
        fin.ignore(); // Ignore newline character after room number
        fin.getline(name, 30); // Read customer name
        fin.getline(address, 50); // Read customer address
        fin.getline(phone, 15); // Read customer phone number
        fin >> days >> fare >> extraServices >> discount; // Read other details
        fin.ignore(); // Ignore newline character after last detail

        // If the current room number matches the room for which services are added
        if (room_no == r) {
            extraServices += additionalCharge; // Add the additional charge for the meal
            roomFound = true; // Set room found flag
            cout << BRIGHT_GREEN << BG_BLACK << "\nExtra services updated successfully." << RESET << " " << "\n"; // Notify success
        }

        // Write the current record to the temporary file
        fout << room_no << endl;
        fout << name << endl;
        fout << address << endl;
        fout << phone << endl;
        fout << days << endl;
        fout << fare << endl;
        fout << extraServices << endl;
        fout << discount << endl;
    }

    // If no matching room was found, display a not found message
    if (!roomFound) {
        cout << BRIGHT_RED << BG_BLACK << "\n\n Room number not found!" << RESET;
    }

    fin.close(); // Close the input file
    fout.close(); // Close the output file

    // Remove the original records file and rename the temporary file to the original file name
    remove("Record.txt");
    rename("Temp.txt", "Record.txt");

    cout << "\n\n Press any key to continue."; // Prompt to continue
    getch(); // Wait for user input
}

void SAPPHIRE_HOTEL::applyDiscount() {
    // Check if the number of days stayed is greater than 7
    if (days > 7) {
        // Apply a 10% discount on the fare if condition is met
        discount = fare * 0.10;
    } else {
        // If not, set the discount to 0
        discount = 0;
    }
}

void SAPPHIRE_HOTEL::generateReport() {
    // Clear the screen and display the header
    system("CLS");
    head();

    ifstream fin("Record.txt"); // Open the records file for reading
    float totalEarnings = 0; // Variable to accumulate total earnings
    int count = 0; // Variable to count total rooms booked

    // Read each record from the file
    while (fin >> room_no) {
        fin.ignore(); // Ignore newline character after room number
        fin.getline(name, 30); // Read customer name
        fin.getline(address, 50); // Read customer address
        fin.getline(phone, 15); // Read customer phone number
        fin >> days >> fare >> extraServices >> discount; // Read other details
        fin.ignore(); // Ignore newline character after last detail

        // Accumulate total earnings by adding fare, extra services, and subtracting discount
        totalEarnings += (fare - discount + extraServices);
        count++; // Increment count of rooms booked
    }

    // Display the report header
    cout << BRIGHT_YELLOW << BG_BLACK;
    cout << "\n\t\t\tReport";
    cout << "\n\t\t\t------" << RESET;

    // Display total rooms booked and total earnings
    cout << "\n\n " << BRIGHT_WHITE << "Total Rooms Booked: " << count;
    cout << "\n " << BRIGHT_WHITE << "Total Earnings: Rs " << fixed << setprecision(2) << totalEarnings;
    cout << "\n\n Press any key to continue."; // Prompt to continue
    getch(); // Wait for user input

    fin.close(); // Close the input file
}

void SAPPHIRE_HOTEL::feedback() {
    // Clear the screen and display the header
    system("CLS");
    head();

    int room_number; // Variable to store the room number
    string feedback; // Variable to store feedback text
    ofstream fout("Feedback.txt", ios::app); // Open feedback file in append mode

    // Use a localized color block for the header
    cout << BRIGHT_YELLOW << BG_BLACK;
    cout << "\n\t\t\t\t*************";
    cout << "\n\t\t\t\t* FEEDBACK *";
    cout << "\n\t\t\t\t*************";
    cout << RESET << endl; // Reset color immediately after the header

    // Prompt for room number and read input
    cout << "\n\n " << BRIGHT_WHITE << "Enter Room Number: " << RESET;
    cin >> room_number;
    cin.ignore(); // Clear the newline character from the input buffer

    // Prompt for feedback and read input
    cout << "\n " << BRIGHT_WHITE << "Please provide your feedback: " << RESET;
    getline(cin, feedback); // Read the feedback string

    // Write feedback to file in a formatted manner
    fout << "Room " << room_number << ": " << feedback << endl;
    fout << "------------------------------" << endl; // Separator for entries

    // Use a localized color block for the thank you message
    cout << "\n\n" << BRIGHT_GREEN;
    cout << " Thank you for your feedback!"; // Thank user for feedback
    cout << RESET << endl; // Reset color immediately after the message

    cout << "\n\n Press any key to continue."; // Prompt to continue
    getch(); // Wait for user input

    fout.close(); // Close the output file
}

void SAPPHIRE_HOTEL::printInvoice() {
    // Clear the screen and display the header
    system("CLS");
    head();

    ifstream fin("Record.txt"); // Open the records file for reading
    int r, flag = 0; // Variable for room number and flag for found room

    // Prompt for room number and read input
    cout << BRIGHT_WHITE << "\nEnter Room Number: " << RESET;
    cin >> r;

    // Read each record from the file
    while (fin >> room_no) {
        fin.ignore(); // Ignore newline character after room number
        fin.getline(name, 30); // Read customer name
        fin.getline(address, 50); // Read customer address
        fin.getline(phone, 15); // Read customer phone number
        fin >> days >> fare >> extraServices >> discount; // Read other details
        fin.ignore(); // Ignore newline character after last detail

        // If the current room number matches the input room number
        if (room_no == r) {
            system("CLS"); // Clear the screen again for displaying invoice
            head();

            // Display invoice header
            cout << BRIGHT_GREEN << BG_BLACK;
            cout << "\n\t\t\t    Invoice Bill";
            cout << "\n\t\t\t    ------------" << RESET;

            // Display details of the room and charges
            cout << "\n " << BRIGHT_WHITE << "Room Number: " << room_no;
            cout << "\n " << BRIGHT_WHITE << "Name: " << name;
            cout << "\n " << BRIGHT_WHITE << "Address: " << address;
            cout << "\n " << BRIGHT_WHITE << "Phone Number: " << phone;
            cout << "\n " << BRIGHT_WHITE << "Staying for " << days << " days.";
            cout << "\n " << BRIGHT_WHITE << "Extra Services Charges: Rs " << extraServices;
            cout << "\n " << BRIGHT_WHITE << "Total Fare: Rs " << fare;
            cout << "\n " << BRIGHT_WHITE << "Discount: Rs " << discount;
            cout << "\n-------------------------------";
            cout << "\n " << BRIGHT_WHITE << "Total Amount Due: Rs " << fare - discount + extraServices;

            flag = 1; // Set flag to indicate room was found
            break; // Exit the loop since the room is found
        }
    }

    // If no matching room was found, display a not found message
    if (flag == 0) {
        cout << BRIGHT_RED << BG_BLACK << "\n Room not found or is vacant." << RESET;
    } else {
        char choice; // Variable to store user's choice for payment
        cout << "\n\n " << BRIGHT_WHITE << "Do you want to Check Out and Pay? (y/n): " << RESET; // Prompt for checkout
        cin >> choice; // Read user's choice

        // If user chooses to check out
        if (choice == 'y' || choice == 'Y') {
            ofstream fout("Temp.txt"); // Open temporary file for writing
            fin.clear(); // Clear EOF flag
            fin.seekg(0); // Reset file pointer to the beginning

            // Read records again to filter out the checked-out room
            while (fin >> room_no) {
                fin.ignore(); // Ignore newline character after room number
                fin.getline(name, 30); // Read customer name
                fin.getline(address, 50); // Read customer address
                fin.getline(phone, 15); // Read customer phone number
                fin >> days >> fare >> extraServices >> discount; // Read other details
                fin.ignore(); // Ignore newline character after last detail

                // If the room number does not match the checked-out room, write to temp file
                if (room_no != r) {
                    fout << room_no << endl;
                    fout << name << endl;
                    fout << address << endl;
                    fout << phone << endl;
                    fout << days << endl;
                    fout << fare << endl;
                    fout << extraServices << endl;
                    fout << discount << endl;
                }
            }

            fin.close(); // Close input file
            fout.close(); // Close output file
            remove("Record.txt"); // Delete the original records file
            rename("Temp.txt", "Record.txt"); // Rename temp file to original file name

            cout << BRIGHT_GREEN << BG_BLACK << "\n\n Payment Successful. Thank you for staying with us!" << RESET; // Notify payment success
        } else {
            cout << BRIGHT_RED << BG_BLACK << "\n\n Payment not made. Please pay at the reception." << RESET; // Notify payment not made
        }
    }

    cout << "\n\n Press any key to continue."; // Prompt to continue
    getch(); // Wait for user input

    fin.close(); // Close the input file
}

int main() {
    SAPPHIRE_HOTEL h; // Create an instance of the SAPPHIRE_HOTEL class
    bool isLoggedIn = false; // Initialize a boolean flag to track login status

    // Loop until the user is logged in
    while (!isLoggedIn) {
        system("CLS"); // Clear the console screen for a clean login interface
        isLoggedIn = h.login(); // Call the login method and update the isLoggedIn flag based on the result
    }

    head(); // Call the head function to display the header or title of the program

    h.main_menu(); // Call the main_menu function to show the main menu options to the user

    return 0; // Return 0 to indicate that the program has ended successfully
}


