Hotel Management System
Overview
The Hotel Management System is a C++-based software solution designed to automate and streamline hotel operations, including room bookings, guest management, billing, and reporting. Named "The Grand Sapphire," this system eliminates the inefficiencies of traditional paper-based methods by providing a secure, user-friendly interface for hotel staff to manage operations efficiently.
This project was developed as part of the Project - I (CS3201) course at the Indian Institute of Information Technology Senapati, Manipur, under the supervision of Dr. Kishorjit Nongmeikapam. The system is implemented using object-oriented programming principles and file-based storage for data persistence.
Features

User Authentication: Secure login module to restrict access to authorized hotel staff.
Room Management: Add, view, modify, and delete room bookings, including checking room availability.
Customer Management: Store and manage guest information such as name, address, and phone number.
Restaurant Module: Handle food orders and add associated charges to guest bills.
Invoice and Reporting: Generate invoices for checkouts and produce reports summarizing hotel operations (e.g., total rooms booked, earnings).
Feedback Module: Collect and store customer feedback for service improvement.
Data Persistence: Store data in files (Record.txt for bookings and customer data, Feedback.txt for feedback).
CRUD Operations: Support for Create, Read, Update, and Delete operations on hotel records.

Objectives

Automate hotel operations to reduce manual errors and improve efficiency.
Provide secure and organized storage for hotel data.
Offer an intuitive, user-friendly interface for staff.
Enable efficient data retrieval and reporting.
Ensure data integrity and security through authentication mechanisms.

System Requirements
Hardware

Standard computer with sufficient storage for program files and data records.

Software

C++ compiler (e.g., g++)
Text editor or IDE (e.g., VS Code, Code::Blocks)
Operating system supporting <iostream>, <fstream>, <string>, and <conio.h> libraries.

Installation

Clone or Download the Project:
Obtain the source code from the repository or project files.


Set Up the Environment:
Ensure a C++ compiler (e.g., g++) is installed.
Verify that the required libraries (iostream, fstream, string, iomanip, conio.h) are supported.


Compile the Code:g++ main.cpp -o hotel_management


Run the Program:./hotel_management


File Permissions:
Ensure the program has read/write permissions for Record.txt and Feedback.txt in the working directory.



Usage

Login:
Enter valid staff credentials to access the system.


Main Menu:
Choose from options such as:
Book a Room
Display Customer Information
View Allotted Rooms
Edit Customer Details
Order Food
Check Out and Print Invoice
Provide Feedback
Generate Report
Exit




Perform Operations:
Follow prompts to input data (e.g., customer details, room numbers, meal choices).
The system saves data to files and generates invoices/reports as needed.



Project Structure

Source Files:
Main implementation in C++ (e.g., main.cpp containing the SAPPHIRE_HOTEL class).


Data Files:
Record.txt: Stores customer and booking information.
Feedback.txt: Stores customer feedback.


Key Modules:
SAPPHIRE_HOTEL Class: Handles core functionalities like authentication, room management, and reporting.
Functions: login(), add(), display(), rooms(), edit(), restaurant(), printInvoice(), feedback(), generateReport().



Testing
The system was tested using a combination of black-box and white-box testing approaches:

Unit Testing: Tested individual functions (e.g., applyDiscount, check).
Integration Testing: Verified interactions between modules (e.g., booking and invoice generation).
System Testing: Simulated real-world scenarios (e.g., complete booking process).
User Acceptance Testing (UAT): Conducted with hotel staff to ensure usability and functionality.

Key Test Cases



Test Case ID
Functionality
Input
Expected Outcome



TC_001
Login
Valid credentials
Access granted


TC_002
Login
Invalid credentials
Access denied


TC_003
Add Customer
Valid customer details
Customer added successfully


TC_019
Print Invoice
Existing room number
Invoice generated correctly


Issues Identified

Weak input validation for invalid room numbers and non-existent records.
Basic authentication mechanism (hardcoded credentials).
Limited error handling for file operations and user input.

Limitations and Future Improvements

Security: Implement stronger authentication (e.g., password hashing).
Error Handling: Add robust error checking for file operations and input validation.
User Interface: Transition to a graphical user interface (GUI) using libraries like Qt or wxWidgets.
Database Integration: Replace file-based storage with a database (e.g., SQLite, MySQL) for scalability.
Advanced Features: Add online booking, payment gateways, and automated notifications.
Mobile Accessibility: Develop a mobile app for remote access.
Reporting: Enhance reports with filters (e.g., date range, room type).

Conclusion
The Hotel Management System provides a functional foundation for automating hotel operations. While it meets the core requirements, enhancements in security, user interface, and data management are recommended for real-world deployment. Future development can focus on GUI integration, database support, and advanced features to create a more robust and scalable solution.
Contributors

Sabinikari Saman (Roll No: 220103031)
Supervisor: Dr. Kishorjit Nongmeikapam

License
This project is submitted as part of academic coursework and is not licensed for commercial use.
