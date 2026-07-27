# University Result Management System

A console-based **University Result Management System** developed in **C language** using **structures and file handling**.

This project provides a complete solution for managing student academic records. It allows users to add, view, search, update, and delete student results with permanent storage using binary files.

---

## 📌 Features

- Add new student records
- Store student details permanently using file handling
- View all student results
- Search student records using Student ID
- Update existing student records
- Delete student records
- Automatic percentage calculation
- Automatic grade calculation
- Input validation for student name and ID
- Prevents duplicate Student IDs
- Validates marks range (0-100)
- Menu-driven console interface

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
- Binary File Operations
- Functions
- Arrays
- Loops
- Conditional Statements
- String Handling
- Input Validation
- CRUD Operations

---

## ⚙️ How to Run the Project

### 1. Clone the Repository

```bash
git clone https://github.com/your-username/University-Result-Management-System.git
```

### 2. Navigate to Project Directory

```bash
cd University-Result-Management-System
```

### 3. Compile the Program

Using GCC compiler:

```bash
gcc result_management.c -o result
```

### 4. Run the Program

### Windows:

```bash
result.exe
```

### Linux/Mac:

```bash
./result
```

---

## 📖 Program Workflow

The system provides the following operations:

```
====================================
 UNIVERSITY RESULT MANAGEMENT SYSTEM
====================================

1. Add Student Result
2. View All Results
3. Search Student By ID
4. Update Student Record
5. Delete Student Record
6. Exit
```

### 1. Add Student Result
- Enter student name and ID
- Enter marks for 5 subjects
- System calculates percentage automatically
- Grade is assigned based on performance
- Record is saved permanently

### 2. View All Results
- Displays all stored student records
- Shows:
  - Student Name
  - Student ID
  - Subject Marks
  - Percentage
  - Grade

### 3. Search Student
- Search records using Student ID
- Displays complete student result information

### 4. Update Student Record
- Modify existing student details
- Update marks
- Recalculate percentage and grade automatically

### 5. Delete Student Record
- Remove student data permanently from the file

---

## 📊 Grade System

| Percentage | Grade |
|------------|-------|
| 90% and above | A+ |
| 80% - 89% | A |
| 70% - 79% | B |
| 60% - 69% | C |
| Below 60% | F |

---

## 📄 Sample Output

```
Name : Sarthak Negi
ID : CS101

Marks:
Subject 1 : 90
Subject 2 : 85
Subject 3 : 88
Subject 4 : 92
Subject 5 : 87

Percentage : 88.40%
Grade : A
```

---

## 🎯 Learning Outcomes

By developing this project, the following concepts were practiced:

- Designing real-world applications using C
- Understanding structures for data organization
- Performing file operations for permanent storage
- Implementing CRUD operations
- Applying input validation techniques
- Improving problem-solving and programming logic

---

## 🚀 Future Improvements

- Add student login authentication
- Add teacher/admin modules
- Add sorting and ranking system
- Generate PDF result reports
- Connect with a database
- Develop GUI version using C graphics or other frameworks

---

## 👨‍💻 Author

**Sarthak Negi**

B.Tech Computer Science Engineering  
Graphic Era Hill University

---

⭐ If you like this project, consider giving it a star on GitHub!
