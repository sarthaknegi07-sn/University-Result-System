# University Result Management System

A console-based **University Result Management System** developed in **C language** using **structures and file handling**.

This project allows users to store, view, and search student academic records efficiently with permanent data storage using a binary file.

---

## 📌 Features

- Add student details and marks
- Calculate average percentage automatically
- View all student results
- Search student result using Student ID
- Input validation for student name
- Input validation for student ID
- Permanent data storage using file handling
- Simple menu-driven console interface

---

## 📂 Project Structure

```
University-Result-Management-System/
│
├── result_management.c     # Main C source code
│
├── results.dat             # Binary file storing student records
│
├── README.md               # Project documentation
│
└── .gitignore              # Git ignored files
```

---

## 🛠️ Technologies Used

- **Programming Language:** C

### Concepts Implemented:
- Structures
- File Handling
- Functions
- Arrays
- Loops
- Conditional Statements
- Input Validation

---

## ⚙️ How to Run the Project

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/University-Result-Management-System.git
```

### 2. Navigate to the Project Folder

```bash
cd University-Result-Management-System
```

### 3. Compile the Program

Using GCC:

```bash
gcc result_management.c -o result
```

### 4. Run the Program

Windows:

```bash
result.exe
```

Linux/Mac:

```bash
./result
```

---

## 📖 Program Workflow

1. Start the program
2. Select an option from the menu:
   - Add Student Result
   - View All Results
   - Search Result by ID
   - Exit

3. Student information is stored inside `results.dat`.
4. Stored records can be accessed whenever the program runs again.

---

## 📊 Student Data Stored

Each student record contains:

- Student Name
- Student ID
- Marks of 5 Subjects
- Average Percentage

Example:

```
Name: Rahul Sharma
ID: ST101

Marks:
Subject 1: 85
Subject 2: 90
Subject 3: 88
Subject 4: 76
Subject 5: 92

Percentage: 86.20%
```

---

## 🎯 Learning Outcomes

Through this project, the following concepts were practiced:

- Creating and using structures in C
- Performing file operations
- Managing records using binary files
- Implementing searching techniques
- Handling user input validation

---

## 🚀 Future Improvements

- Add update student records feature
- Add delete student records feature
- Add grade calculation system
- Add sorting functionality
- Add database integration
- Create a graphical user interface

---

## 👨‍💻 Author

**Sarthak Negi**

B.Tech Computer Science Engineering  
Graphic Era Hill University

---

⭐ If you like this project, consider giving it a star on GitHub.
