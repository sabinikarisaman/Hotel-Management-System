# 🏨 Hotel Management System – "Grand Sapphire"

This is a C++ based Hotel Management System developed as part of the B.Tech Project-I course (CS3201) at the Indian Institute of Information Technology, Senapati, Manipur. The system automates key hotel operations, including room bookings, guest management, restaurant services, billing, feedback, and reporting. It uses file handling for data persistence and offers a menu-driven console interface for staff.

---

## 📌 Project Overview

The Hotel Management System is designed to automate and streamline key operations of a hotel such as:

- Room bookings
- Guest check-ins and check-outs
- Restaurant ordering
- Billing and invoice generation
- Feedback collection
- Report generation

The system uses file handling for data persistence (`Record.txt` and `Feedback.txt`) and offers a secure, menu-driven console interface for staff.

---

## 🎯 Objectives

- Automate manual hotel processes to eliminate paper-based operations to provide secure storage of guest and room information.
- Support complete CRUD operations (Create, Read, Update, Delete)
- Implement basic staff authentication
- Improve operational efficiency and guest satisfaction

---

## 🛠️ Features

- 🗝️ **Authentication** – Simple login system for hotel staff (username: admin, password: password)
- 🛏️ **Room Management** – Book, edit, and view room reservations
- 🧾 **Billing Module** – Automatic fare calculation and invoice printing
- 🍽️ **Restaurant Services** – Take food orders linked to room bills
- 📊 **Reports** – Generate daily revenue and occupancy reports
- ✍️ **Feedback Module** – Collect customer feedback for analysis

---

## 📂 Files

- `main.cpp` – Main source code implementing the system logic
- `Record.txt` – Stores booking and billing information in a comma-separated format (e.g., Room Number, Guest Name, Check-in Date, Check-out Date, Bill Amount).
- `Feedback.txt` – Stores customer feedback as free-form text entries.

---

## 💻 Technologies Used

- Language: C++
- Libraries: `iostream`, `fstream`, `iomanip`, `conio.h` (Standard C++ libraries included with most compilers)
- Storage: File-based system using `.txt` files
- Platform: Windows (tested using MinGW / GCC)

---

## ▶️ How to Run

### Option 1: Using Command Line (MinGW / GCC)

Clone or download this repository:

```bash
git clone https://github.com/sabinikarisaman/Hotel-Management-System.git
Use code with caution.
Markdown
Navigate to the project folder:
cd Hotel-Management-System
Use code with caution.
Bash
Compile the program:
g++ main.cpp -o hotel.exe
Use code with caution.
Bash
Run the executable:
./hotel.exe

# **Note:** If the command `./hotel.exe` does not work, try `./a.exe` or ensure your system's PATH includes the directory where `g++` is installed.
Use code with caution.
Bash
Option 2: Using Code::Blocks or Dev C++
Open main.cpp in your IDE
Create a new project (if required)
Add main.cpp to the project
Build and run the program using the Run button (usually F9)
🧪 Testing Summary
Unit, integration, and system-level testing performed.
Regression and User Acceptance Testing (UAT) completed.
Example Test Cases:
Booking a room for a specific date range and verifying the room is unavailable for overlapping bookings.
Generating a bill for a guest with restaurant charges and confirming the total amount is calculated correctly.
All core functionalities tested successfully using defined test cases
🧠 Future Improvements
Replace file storage with an SQL database (e.g., SQLite) to improve data management and scalability.
Add GUI using Qt or wxWidgets for a more user-friendly experience, potentially targeting cross-platform compatibility.
Improve authentication with password hashing (e.g., bcrypt or Argon2) to enhance security.
Add advanced search and filtering capabilities to the report generation module, allowing users to generate reports based on specific criteria (e.g., date range, room type, guest name).
Develop a basic mobile interface (using a framework like React Native) for staff to access key functionalities on the go.
👨‍💻 Author
Sabinikari Saman
Pursuing B.Tech in Computer Science & Engineering (AI & DS)
Indian Institute of Information Technology, Senapati, Manipur
Roll No: 220103031
📃 License
This project is developed as an academic submission. Please contact the author for reuse or collaboration.
