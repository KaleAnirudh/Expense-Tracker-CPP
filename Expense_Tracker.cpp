#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Expense
{
    string title;
    double amount;
    string date;
};

void AddExpense()
{
    ofstream file("expense.txt", ios::app);
    if (!file)
    {
        cout << "Error opening file\n";
        return;
    }
    Expense e;
    cout << "Enter expense title: ";
    getline(cin >> ws, e.title);
    while (true)
    {
        cout << "Enter expense amount: ";
        cin >> e.amount;
        if (e.amount <= 0)
        {
            cout << "Invalid Amount!!\nTry Again : ";
        }
        else
        {
            break;
        }
    }
    cout << "Enter expense date (DD-MM-YYYY): ";
    cin >> e.date;
    file << e.title << "|" << e.amount << "|" << e.date << endl;
    file.close();
    cout << "\nExpense added successfully\n\n";
}

void ViewExpense()
{
    ifstream file("expense.txt");
    if (!file)
    {
        cout << "Error opening file\n";
        return;
    }
    string line;
    bool found = false;
    int count = 1;
    cout << "\n===== YOUR EXPENSES =====\n\n";
    while (getline(file, line))
    {
        Expense e;
        stringstream ss(line);
        string amount;
        getline(ss, e.title, '|');
        getline(ss, amount, '|');
        getline(ss, e.date);
        e.amount = stod(amount);
        cout << count << ". " << e.title << " | Rs." << e.amount << " | " << e.date << endl;
        count++;
        found = true;
    }
    if (!found)
    {
        cout << "No expenses available\n";
    }
    file.close();
}

void DeleteExpense()
{
    ifstream file("expense.txt");
    if (!file)
    {
        cout << "Error opening file\n";
        return;
    }
    vector<Expense> expenses;
    string line;
    while (getline(file, line))
    {
        Expense e;
        string amount;
        stringstream ss(line);
        getline(ss, e.title, '|');
        getline(ss, amount, '|');
        getline(ss, e.date);
        e.amount = stod(amount);
        expenses.push_back(e);
    }
    file.close();
    if (expenses.empty())
    {
        cout << "No expenses to delete\n";
        return;
    }
    cout << "\n===== YOUR EXPENSES =====\n\n";
    for (int i = 0; i < expenses.size(); i++)
    {
        cout << i + 1 << ". " << expenses[i].title << " | Rs." << expenses[i].amount << " | " << expenses[i].date << endl;
    }
    int choice;
    cout << "\nEnter the expense to delete: ";
    cin >> choice;
    if (choice < 1 || choice > expenses.size())
    {
        cout << "Invalid expense number!\n";
        return;
    }
    expenses.erase(expenses.begin() + choice - 1);
    ofstream outfile("expense.txt");
    for (int i = 0; i < expenses.size(); i++)
    {
        outfile << expenses[i].title << "|" << expenses[i].amount << "|" << expenses[i].date << endl;
    }
    outfile.close();
    cout << "\nExpense deleted successfully\n\n";
}

void TotalExpense()
{
    ifstream file("expense.txt");
    if (!file)
    {
        cout << "Error opening file\n";
        return;
    }
    double total = 0;
    string line;
    bool found = false;
    while (getline(file, line))
    {
        Expense e;
        string amount;
        stringstream ss(line);
        getline(ss, e.title, '|');
        getline(ss, amount, '|');
        getline(ss, e.date);
        e.amount = stod(amount);
        total = total + e.amount;
        found = true;
    }
    file.close();
    if (!found)
    {
        cout << "No expense available\n";
        return;
    }
    cout << "Total Expense : Rs." << total << "\n\n";
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\n==== Expense Tracker ====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expense\n";
        cout << "3. Delete Expense\n";
        cout << "4. Total Expense\n";
        cout << "5. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            AddExpense();
            break;
        case 2:
            ViewExpense();
            break;
        case 3:
            DeleteExpense();
            break;
        case 4:
            TotalExpense();
            break;
        case 5:
            cout << "ThankYou for using Expense Tracker!!\n";
            return 0;
        default:
            cout << "Invalid Choice\n";
        }
    }
    return 0;
}