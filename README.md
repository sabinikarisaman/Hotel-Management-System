# 🏨 The Grand Sapphire - Hotel Management System

This is a **C++-based Hotel Management System** designed to automate and streamline hotel operations including bookings, guest management, billing, food orders, and reporting. Developed as part of the **Project-I (CS3201)** course at the **Indian Institute of Information Technology, Senapati, Manipur**, under the supervision of **Dr. Kishorjit Nongmeikapam**.

---

## 📌 Project Overview

The Grand Sapphire replaces inefficient manual processes with a secure, user-friendly interface for hotel staff, ensuring:
- Efficient data management
- Streamlined guest service
- Improved satisfaction

---

## ✨ Features

- 🔐 **User Authentication:** Secure login for authorized hotel staff.
- 🛏️ **Room Management:** Create, view, update, and delete room bookings.
- 👤 **Customer Management:** Store and manage guest details.
- 🍽️ **Restaurant Module:** Add food orders to guest bills.
- 🧾 **Invoice & Reports:** Generate bills and hotel operation summaries.
- 💬 **Feedback Module:** Collect customer feedback.
- 💾 **Data Persistence:** File-based storage (`Record.txt`, `Feedback.txt`).
- 🔄 **CRUD Operations:** Full create/read/update/delete support.

---

## 🎯 Objectives

- Automate hotel operations to reduce manual errors.
- Maintain secure and structured data.
- Provide an intuitive interface for staff use.
- Enable quick reporting and data retrieval.
- Secure access with login authentication.

---

## ⚙️ Installation

### 🧰 Prerequisites

- **Hardware:** Any standard PC
- **Software:**
  - C++ Compiler (e.g., `g++`)
  - Text Editor or IDE (e.g., VS Code, Code::Blocks)
  - Operating system supporting: `<iostream>`, `<fstream>`, `<string>`, `<iomanip>`, `<conio.h>`

### 🧾 Steps

```bash
# Clone the repository
git clone https://github.com/sabinikarisaman/Hotel-Management-System.git
cd Hotel-Management-System

# Compile the code
g++ main.cpp -o hotel_management

# Run the program
./hotel_management
```

Ensure the program has read/write permissions for `Record.txt` and `Feedback.txt`.

---

## ▶️ Usage

### 🔑 Login

Enter valid staff credentials to begin.

### 🧭 Main Menu Options

- Book a room
- View customer info
- View allotted rooms
- Edit customer info
- Order food
- Checkout & print invoices
- Provide feedback
- Generate reports
- Exit

### 📝 Perform Operations

Follow on-screen prompts to:
- Add guest/room/meal data
- Generate invoices and reports
- Save and retrieve from file storage

---

## 📁 Project Structure

```
Hotel-Management-System/
├── main.cpp           # Main source code
├── Record.txt         # Guest & booking records
├── Feedback.txt       # Customer feedback
├── README.md          # Documentation
```

---

## 🧩 Key Modules

### `SAPPHIRE_HOTEL` Class

Handles:
- Authentication
- Room & guest management
- Invoicing and reporting

### 🔑 Key Functions

- `login()`: Staff authentication
- `add()`, `display()`, `rooms()`, `edit()`, `delete_rec()`: Booking and data management
- `restaurant()`: Food order integration
- `printInvoice()`, `generateReport()`: Billing and analytics
- `feedback()`: Records feedback

---

## 🧪 Testing

### ✅ Testing Methods

- **Black-box Testing:** Tested from user POV (e.g., invoice generation)
- **White-box Testing:** Checked internal logic (e.g., discount logic)
- **Integration Testing:** Checked module communication
- **User Acceptance Testing (UAT):** Verified with real hotel staff

### 🧾 Sample Test Cases

| Test Case ID | Functionality    | Input                | Expected Outcome          |
|--------------|------------------|----------------------|---------------------------|
| TC_001       | Login            | Valid credentials    | Access granted            |
| TC_002       | Login            | Invalid credentials  | Access denied             |
| TC_003       | Add Customer     | Valid guest details  | Customer added            |
| TC_019       | Print Invoice    | Existing room number | Invoice generated         |

---

## 🐞 Known Issues

- Hardcoded credentials (basic auth)
- Limited validation for room numbers
- Weak error handling on file operations

---

## 🚀 Limitations & Future Improvements

- 🔐 **Security:** Add password hashing/salting
- 🧱 **Validation:** Improve input checks
- 🖥️ **UI:** Add graphical UI (e.g., Qt, wxWidgets)
- 🗃️ **Database:** Migrate to MySQL/SQLite
- 🌐 **Advanced Features:** Online booking, payments, notifications
- 📱 **Mobile:** Build a mobile app
- ☁️ **Cloud Support:** Enable cloud sync and backups

---

## 🤝 Contributing

Contributions are welcome!

1. Fork the repo
2. Create a feature branch:
   ```bash
   git checkout -b feature-branch
   ```
3. Commit your changes:
   ```bash
   git commit -m "Add feature"
   ```
4. Push the changes:
   ```bash
   git push origin feature-branch
   ```
5. Open a **Pull Request**

---

## 👨‍💻 Contributors

- **Sabinikari Saman** (Roll No: 220103031)  
- **Supervisor:** Dr. Kishorjit Nongmeikapam

---

## 📜 License

This project is developed for **academic purposes only** and is **not licensed** for commercial use.

---

## 🙏 Acknowledgments

- Special thanks to **Dr. Kishorjit Nongmeikapam** for his continuous guidance.
- Thanks to **IIIT Senapati, Manipur** for the academic platform.

---

### 📬 For issues or suggestions, please [open an issue](https://github.com/sabinikarisaman/Hotel-Management-System/issues) on the GitHub repository.
