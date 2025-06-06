
# 🏨 The Grand Sapphire Hotel Management System

This is a console-based Hotel Management System built in **C++**. It provides functionalities to manage room bookings, generate invoices, handle restaurant services, and collect customer feedback.

---

## ✨ Features

- Room Booking with customer details
- Room availability check
- Restaurant service with meals (breakfast, lunch, dinner)
- Automatic discount for long stays
- Invoice generation at checkout
- Customer feedback collection
- Staff login with secure password masking
- Data persistence using file operations

---

## 📂 Project Files

- `main.cpp`: Main source code containing the hotel system logic
- `Record.txt`: Stores all customer booking records
- `Feedback.txt`: Stores feedback from customers
- `README.md`: Project documentation

---

## 🚀 Getting Started

### 🔧 Prerequisites

- C++ compiler (e.g. g++, MSVC)
- Console that supports ANSI color codes (Windows Terminal, Linux shell, etc.)

### 🛠️ How to Compile

```bash
g++ main.cpp -o hotel_app
```

### ▶️ How to Run

```bash
./hotel_app
```

On **Windows**, you may run:

```cmd
hotel_app.exe
```

---

## 🔐 Staff Login

- **Username**: `admin`
- **Password**: `sapphire123`  
  _(Input is hidden during typing)_

---

## 📝 Notes

- Ensure the `Record.txt` and `Feedback.txt` files are in the same directory as the executable.
- These files will be auto-created if they don't exist, but must be writable.
- If you're getting errors when writing to `Record.txt`, check:
  - File permissions
  - Antivirus/file lock issues
  - Whether the program has necessary write access in that folder

---

## 💬 Feedback Format

Sample entry in `Feedback.txt`:
```
Room 104: The food was so delicious.
------------------------------
```

---

## 📜 License

This project is open-source and can be modified freely for educational or personal use.
