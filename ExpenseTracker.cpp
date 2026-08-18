#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Expense {
    string category;
    double amount;
    string date;
};

// Save expenses to file
void saveExpenses(const vector<Expense>& expenses) {

    ofstream file("expenses.txt");

    for (const Expense& e : expenses) {
        file << e.category << " "
             << e.amount << " "
             << e.date << endl;
    }

    file.close();
}

// Load expenses from file
void loadExpenses(vector<Expense>& expenses) {

    ifstream file("expenses.txt");

    Expense e;

    while (file >> e.category >> e.amount >> e.date) {
        expenses.push_back(e);
    }

    file.close();
}

// Add expense
void addExpense(vector<Expense>& expenses) {

    Expense e;

    cout << "\nEnter category: ";
    cin >> e.category;

    cout << "Enter amount: ";
    cin >> e.amount;

    cout << "Enter date (DD/MM/YYYY): ";
    cin >> e.date;

    expenses.push_back(e);

    saveExpenses(expenses);

    cout << "\nExpense added successfully!\n";
}

// View all expenses
void viewExpenses(const vector<Expense>& expenses) {

    if (expenses.empty()) {
        cout << "\nNo expenses found.\n";
        return;
    }

    cout << "\n===== ALL EXPENSES =====\n";

    for (const Expense& e : expenses) {

        cout << "Category : " << e.category << endl;
        cout << "Amount   : Rs. " << e.amount << endl;
        cout << "Date     : " << e.date << endl;
        cout << "------------------------\n";
    }
}

// Calculate total expense
void totalExpense(const vector<Expense>& expenses) {

    double total = 0;

    for (const Expense& e : expenses) {
        total += e.amount;
    }

    cout << "\nTotal Expense: Rs. " << total << endl;
}

// Search expense by category
void searchExpense(const vector<Expense>& expenses) {

    string category;
    bool found = false;

    cout << "\nEnter category to search: ";
    cin >> category;

    cout << "\n===== SEARCH RESULTS =====\n";

    for (const Expense& e : expenses) {

        if (e.category == category) {

            cout << "Category : " << e.category << endl;
            cout << "Amount   : Rs. " << e.amount << endl;
            cout << "Date     : " << e.date << endl;
            cout << "------------------------\n";

            found = true;
        }
    }

    if (!found) {
        cout << "Expense not found.\n";
    }
}

// Delete expense
void deleteExpense(vector<Expense>& expenses) {

    string category;

    cout << "\nEnter category to delete: ";
    cin >> category;

    for (auto it = expenses.begin(); it != expenses.end(); ++it) {

        if (it->category == category) {

            expenses.erase(it);

            saveExpenses(expenses);

            cout << "Expense deleted successfully!\n";
            return;
        }
    }

    cout << "Expense not found.\n";
}

int main() {

    vector<Expense> expenses;

    // Load previously saved expenses
    loadExpenses(expenses);

    int choice;

    do {

        cout << "\n==============================\n";
        cout << "       EXPENSE TRACKER\n";
        cout << "==============================\n";

        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Total Expense\n";
        cout << "4. Search Expense\n";
        cout << "5. Delete Expense\n";
        cout << "6. Exit\n";

        cout << "==============================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                addExpense(expenses);
                break;

            case 2:
                viewExpenses(expenses);
                break;

            case 3:
                totalExpense(expenses);
                break;

            case 4:
                searchExpense(expenses);
                break;

            case 5:
                deleteExpense(expenses);
                break;

            case 6:
                cout << "\nThank you for using Expense Tracker!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}