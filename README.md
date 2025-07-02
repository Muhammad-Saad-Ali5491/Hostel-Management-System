# 🏨 Hostel Management System

Welcome to the **Hostel Management System**, a C++ console-based application designed to streamline hostel operations for administrators and customers. This project provides a robust solution for managing rooms, customer data, and historical records with a user-friendly interface. 🚀

## 📋 Table of Contents
- [Project Overview](#project-overview)
- [Features](#features)
- [File Structure](#file-structure)
- [Dependencies](#dependencies)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Code Highlights](#code-highlights)
- [Contributing](#contributing)
- [License](#license)

## 🌟 Project Overview
The Hostel Management System is a console-based application developed in C++ to manage hostel operations efficiently. It supports user authentication (signup/login), room management, customer management, and history tracking. The system uses file-based storage for persistent data and includes a doubly linked list for customer data and a stack for history records. 🛠️

The application is divided into admin and customer service functionalities, with an intuitive menu-driven interface. It also features ASCII art for a welcoming introduction and error handling for robust operation.

## ✨ Features
- **User Authentication** 🔐
  - Signup: Create new accounts with a username and password.
  - Login: Securely access the system with credentials stored in `Login_IDs.txt`.
- **Admin Options** 🧑‍💼
  - Add rooms with details like room number, floor, and price.
  - Display all rooms with availability status.
  - Modify room details (room number, floor, availability, price).
- **Customer Services** 🧑‍🤝‍🧑
  - Add customers with details (name, CNIC, contact, address, room, floor, and check-in date).
  - Modify customer details.
  - Check out customers and calculate bills based on room price and stay duration.
  - View the customer list.
- **History Management** 📜
  - View and clear the history of removed customers stored in `history.txt`.
- **File-Based Storage** 💾
  - Persistent storage of customer and room data in `costumer.txt` and `room.txt`.
  - History of removed customers stored in `history.txt`.
- **Date Calculations** 📅
  - Calculate the number of days between check-in and check-out dates for billing.
- **Cross-Platform Support** 🖥️
  - Clear screen functionality for Windows using `system("cls")`.

## 📂 File Structure
Here's an overview of the project's files:

```
Hostel-Management-System/
│
├── 📜 ClearAndWait.h       # Screen clearing and input waiting utilities
├── 📜 costumer.h           # Customer management with doubly linked list
├── 📜 date.h               # Date structure and days calculation logic
├── 📜 History.h            # History management with stack implementation
├── 📜 introduction.h       # Displays ASCII art introduction
├── 📜 MainMenu.h           # Menu display and authentication logic
├── 📜 Room.h               # Room management with file operations
├── 📜 main.cpp             # Main program logic and menu navigation
├── 📜 introduction.txt     # ASCII art for the introduction screen
├── 📜 Login_IDs.txt        # Stores user credentials
├── 📜 costumer.txt         # Stores customer data
├── 📜 room.txt             # Stores room data
├── 📜 history.txt          # Stores history of removed customers
└── 📜 README.md            # Project documentation (this file)
```

## 🛠️ Dependencies
- **C++ Compiler**: A standard C++ compiler (e.g., g++, MSVC) with C++11 or later support.
- **Operating System**: Windows (for `system("cls")` in `ClearAndWait.h`). For other OS, modify the `clearScreen()` function.
- **Standard Libraries**:
  - `<iostream>`, `<fstream>`, `<sstream>`, `<string>`, `<algorithm>`

No external libraries are required, making the project lightweight and portable. 🪶

## 📥 Installation
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Muhammad-Saad-Ali5491/Hostel-Management-System.git
   ```
   (Replace with your repository URL if hosted.)

2. **Navigate to the Project Directory**:
   ```bash
   cd hostel-management-system
   ```

3. **Compile the Code**:
   Use a C++ compiler to build the project. For example, with g++:
   ```bash
   g++ main.cpp -o hostel_management
   ```

4. **Run the Executable**:
   ```bash
   ./hostel_management
   ```

## 🚀 Usage
1. **Start the Program**:
   Run the compiled executable. The program displays an ASCII art introduction from `introduction.txt`.

2. **Sign Up or Log In**:
   - Choose **1** to sign up with a new account (stored in `Login_IDs.txt`).
   - Choose **2** to log in with existing credentials.

3. **Main Menu**:
   After successful login, choose from:
   - **1: Admin Options**: Manage rooms (add, display, modify).
   - **2: Customer Services**: Manage customers (add, modify, check out, view list).
   - **3: View History**: View or clear the history of removed customers.
   - **9: Exit**: Save data and exit.

4. **Customer Checkout**:
   - Enter customer name and CNIC to calculate the bill based on room price and stay duration.
   - The system updates room availability and saves removed customer data to `history.txt`.

5. **File Operations**:
   - Customer data is saved to `costumer.txt`.
   - Room data is saved to `room.txt`.
   - History is saved to `history.txt`.

## 🧠 How It Works
- **Data Structures**:
  - **Doubly Linked List** (`costumer.h`): Manages customer data with `node` struct for easy insertion, deletion, and modification.
  - **Stack** (`History.h`): Stores removed customer records for history tracking.
- **File Handling**:
  - Data is read from and written to text files (`costumer.txt`, `room.txt`, `history.txt`) for persistence.
  - The `saveData` and `resaveData` functions in `costumer.h` handle customer data storage.
- **Room Management**:
  - The `rooms` class in `Room.h` manages room details, including availability and price.
  - File operations ensure room data is updated correctly.
- **Date Calculations**:
  - The `date.h` file calculates the number of days between two dates for billing purposes, accounting for leap years.
- **User Interface**:
  - Menu-driven interface with clear prompts and error handling.
  - Screen clearing (`ClearAndWait.h`) enhances user experience on Windows.

## 💻 Code Highlights
- **Customer Management** (`costumer.h`):
  ```cpp
  void addCostumer(string name, string CNIC, string contact, string address, int room, int floor, int day, int month, int year) {
      node* newNode = new node(name, CNIC, contact, address, room, floor, day, month, year);
      if (!head) {
          head = tail = newNode;
      } else {
          newNode->prev = tail;
          tail->next = newNode;
          tail = newNode;
      }
  }
  ```
  This implements a doubly linked list for efficient customer data management.

- **Date Calculation** (`date.h`):
  ```cpp
  int calculateDaysBetweenDates(const Date& date1, const Date& date2) {
      int days = 0;
      Date tempDate1 = date1;
      Date tempDate2 = date2;
      if (tempDate1.year > tempDate2.year || ...) {
          std::swap(tempDate1, tempDate2);
      }
      while (...) {
          days++;
          tempDate1.day++;
          if (tempDate1.day > daysInMonth(tempDate1.month, tempDate1.year)) {
              tempDate1.day = 1;
              tempDate1.month++;
              if (tempDate1.month > 12) {
                  tempDate1.month = 1;
                  tempDate1.year++;
              }
          }
      }
      return days;
  }
  ```
  This calculates the exact number of days between two dates, handling leap years.

- **File Handling** (`Room.h`):
  ```cpp
  void addRoom(int roomNo, int floorNo, double price) {
      this->roomNo = roomNo;
      this->floorNo = floorNo;
      this->available = true;
      this->price = price;
      ofstream fout("room.txt", ios::app);
      if (!fout) {
          cout << "file doesn't exist" << endl;
      } else {
          fout << this->floorNo << "-" << this->roomNo << "-" << this->available << "-" << this->price << endl;
      }
  }
  ```
  This ensures room data is appended to `room.txt` for persistent storage.

## 🤝 Contributing
Contributions are welcome! 🙌 To contribute:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature/your-feature`).
3. Make your changes and commit (`git commit -m 'Add your feature'`).
4. Push to the branch (`git push origin feature/your-feature`).
5. Open a pull request.

Please ensure your code follows the existing style and includes appropriate comments.

## 📜 License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Happy managing! 🏡 If you have any questions or need assistance, feel free to open an issue or contact the repository owner. 😊
