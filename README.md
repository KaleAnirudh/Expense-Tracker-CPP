# 💰 Expense Tracker (C++)
A simple console-based Expense Tracker built using C++. This project allows users to manage their daily expenses by storing data in a text file. It demonstrates the use of file handling, structures, vectors, string streams, and basic CRUD operations.
---
## 🚀 Features
- ➕ Add a new expense
- 📋 View all expenses
- ❌ Delete an existing expense
- 💵 Calculate total expenses
- 💾 Stores data permanently using file handling (`expense.txt`)
- ✅ Input validation for expense amount
---
## 🛠️ Technologies Used
-  C++
- File Handling (`ifstream`, `ofstream`)
- Structures (`struct`)
- Vectors (`vector`)
- String Stream (`stringstream`)
- Standard Template Library (STL)
---
## 📂 Project Structure
```
Expense-Tracker/
│── main.cpp
│── expense.txt
└── README.md
```
---
## 📌 How It Works
### Add Expense
- Enter the expense title.
- Enter the expense amount.
- Enter the expense date.
- The expense is saved to `expense.txt`.
### View Expenses
Displays all saved expenses in a numbered list.

### Delete Expense
- Displays all expenses.
- Select the expense number to delete.
- Updates the file after deletion.

### Total Expense
Reads all expenses from the file and calculates the total amount spent.
---
## 📖 Concepts Practiced
- Functions
- Structures
- File Handling
- Vectors
- String Parsing using `stringstream`
- Input Validation
- Loops and Conditional Statements
---
## ▶️ Sample Output
```
==== Expense Tracker ====

1. Add Expense
2. View Expense
3. Delete Expense
4. Total Expense
5. Exit

Enter your choice: 1

Enter expense title: Lunch
Enter expense amount: 250
Enter expense date (DD-MM-YYYY): 26-06-2026

Expense added successfully!
```
---
## 🔮 Future Improvements

- Edit an existing expense
- Search expenses by title or date
- Monthly expense summary
- Expense categories (Food, Travel, Shopping, etc.)
- Better date validation
- Export expenses to CSV
- Menu using OOP (Classes)
---
## 👨‍💻 Author
**Anirudha Kale**
Built as part of my C++ learning journey to practice file handling and data management.
