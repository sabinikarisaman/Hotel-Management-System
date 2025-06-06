# 🏨 Hotel Management System – "Grand Sapphire"

This is a C++ based Hotel Management System developed as part of the B.Tech Project-I course (CS3201) at the Indian Institute of Information Technology, Senapati, Manipur.

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

- Eliminate manual hotel processes with automation
- Provide secure storage for guest and room information
- Support complete CRUD operations (Create, Read, Update, Delete)
- Implement basic staff authentication
- Improve operational efficiency and guest satisfaction

---

## 🛠️ Features

- 🗝️ **Authentication** – Simple login system for hotel staff  
- 🛏️ **Room Management** – Book, edit, and view room reservations  
- 🧾 **Billing Module** – Automatic fare calculation and invoice printing  
- 🍽️ **Restaurant Services** – Take food orders linked to room bills  
- 📊 **Reports** – Generate daily revenue and occupancy reports  
- ✍️ **Feedback Module** – Collect customer feedback for analysis  

---

## 📂 Files

- `main.cpp` – Main source code implementing the system logic  
- `Record.txt` – Stores booking and billing information  
- `Feedback.txt` – Stores customer feedback  

---

## 💻 Technologies Used

- Language: C++  
- Libraries: `iostream`, `fstream`, `iomanip`, `conio.h`  
- Storage: File-based system using `.txt` files  
- Platform: Windows (tested using MinGW / GCC)  

---

## ▶️ How to Run

### Option 1: Using Command Line (MinGW / GCC)

Clone or download this repository:

```bash
git clone https://github.com/sabinikarisaman/Hotel-Management-System.git
Navigate to the project folder:

bash
Copy
Edit
cd Hotel-Management-System
Compile the program:

bash
Copy
Edit
g++ main.cpp -o hotel.exe
Run the executable:

bash
Copy
Edit
./hotel.exe
Option 2: Using Code::Blocks or Dev C++
Open main.cpp in your IDE

Create a new project (if required)

Add main.cpp to the project

Build and run the program using the Run button (usually F9)

🧪 Testing Summary
Unit, integration, and system-level testing performed

Regression and User Acceptance Testing (UAT) completed

All core functionalities tested successfully using defined test cases

🧠 Future Improvements
Replace file storage with SQL database

Add GUI using Qt or wxWidgets

Improve authentication with password encryption

Add customer search and report filtering features

Support mobile and cloud-based deployment

👨‍💻 Author
Sabinikari Saman
Pursuing B.Tech in Computer Science & Engineering (AI & DS)
Indian Institute of Information Technology, Senapati, Manipur
Roll No: 220103031

📃 License
This project is developed as an academic submission. Please contact the author for reuse or collaboration.
