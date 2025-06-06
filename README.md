The Grand Sapphire - Hotel Management System
Project Overview
The Grand Sapphire Hotel Management System is a C++-based application designed to automate and streamline hotel operations, including room bookings, guest management, billing, restaurant orders, and reporting. This system replaces inefficient manual processes with a secure, user-friendly interface for hotel staff, ensuring efficient data management and improved guest satisfaction.
This project was developed as part of the Project - I (CS3201) course at the Indian Institute of Information Technology Senapati, Manipur, under the supervision of Dr. Kishorjit Nongmeikapam.
Features

User Authentication: Secure login for authorized hotel staff.
Room Management: Create, view, update, and delete room bookings, with availability checks.
Customer Management: Store and manage guest details (name, address, phone).
Restaurant Module: Process food orders and integrate charges into guest bills.
Invoice and Reporting: Generate invoices for checkouts and reports on hotel operations (e.g., earnings, occupancy).
Feedback Module: Collect and store customer feedback.
Data Persistence: Use file-based storage (Record.txt for bookings, Feedback.txt for feedback).
CRUD Operations: Support for Create, Read, Update, and Delete operations on hotel records.

Objectives

Automate hotel operations to reduce errors and improve efficiency.
Provide secure, organized data storage.
Offer an intuitive interface for staff.
Enable fast data retrieval and comprehensive reporting.
Ensure data security through authentication.

Installation
Prerequisites

Hardware: Standard computer with sufficient storage.
Software:
C++ compiler (e.g., g++)
Text editor or IDE (e.g., VS Code, Code::Blocks)
Operating system supporting <iostream>, <fstream>, <string>, <iomanip>, and <conio.h> libraries.



Steps

Clone the Repository:git clone https://github.com/sabinikarisaman/Hotel-Management-System.git
cd Hotel-Management-System


Compile the Code:g++ main.cpp -o hotel_management


Run the Program:./hotel_management


File Permissions:
Ensure the program has read/write permissions for Record.txt and Feedback.txt in the project directory.



Usage

Login:
Enter valid staff credentials to access the system.


Main Menu:
Navigate options to:
Book a room
View customer information
Check allotted rooms
Edit customer details
Order food
Check out and print invoices
Provide feedback
Generate reports
Exit




Perform Operations:
Follow prompts to input data (e.g., guest details, room numbers, meal choices).
Data is saved to files, and invoices/reports are generated as needed.



Project Structure
Hotel-Management-System/
├── main.cpp              # Main source code with SAPPHIRE_HOTEL class
├── Record.txt            # Stores booking and customer data
├── Feedback.txt          # Stores customer feedback
├── README.md             # Project documentation

Key Modules

SAPPHIRE_HOTEL Class: Core class handling authentication, room/customer management, and reporting.
Key Functions:
login(): Authenticates staff.
add(), display(), rooms(), edit(), delete_rec(): Manage bookings and customer data.
restaurant(): Handles food orders.
printInvoice(), generateReport(): Generate invoices and reports.
feedback(): Records customer feedback.



Testing
The system underwent rigorous testing:

Black-box Testing: Verified functionality from a user perspective (e.g., correct invoice generation).
White-box Testing: Analyzed code paths (e.g., discount calculations).
Integration Testing: Ensured module interactions (e.g., booking to invoicing).
User Acceptance Testing (UAT): Conducted with hotel staff to validate usability.

Sample Test Cases



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


Known Issues

Basic authentication (hardcoded credentials).
Weak input validation for invalid room numbers.
Limited error handling for file operations.

Limitations and Future Improvements

Security: Implement password hashing and salting.
Error Handling: Enhance validation and error messages.
User Interface: Develop a graphical interface using Qt or wxWidgets.
Database Integration: Migrate to SQLite or MySQL for scalability.
Advanced Features: Add online booking, payment gateways, and notifications.
Mobile Support: Create a mobile app for remote access.
Cloud Deployment: Enable cloud-based access and backups.

Contributing
Contributions are welcome! To contribute:

Fork the repository.
Create a new branch (git checkout -b feature-branch).
Make changes and commit (git commit -m "Add feature").
Push to the branch (git push origin feature-branch).
Open a Pull Request.

Contributors

Sabinikari Saman (Roll No: 220103031)
Supervisor: Dr. Kishorjit Nongmeikapam

License
This project is for academic purposes and not licensed for commercial use.
Acknowledgments

Dr. Kishorjit Nongmeikapam for guidance and support.
Indian Institute of Information Technology Senapati, Manipur for providing the academic framework.


For issues or suggestions, please open an issue on the GitHub repository.
