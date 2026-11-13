#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* My First CPP Project */
    /* Declaration of variables */
    const int MAX = 50;
    string categories[MAX];
    float amounts[MAX];
    int count = 0;
    float pocketMoney;

    /* user input taking */
    cout << "Enter your monthly pocket money: ";
    cin >> pocketMoney;
    cout << "Your pocket money: Rs. " << pocketMoney << endl;

    /* Menu system - user choice */
    int choice;

    do
    {
        cout << "\n----------- MENU -----------\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Show Total & Savings\n";
        cout << "4. Investment Suggestion\n";
        cout << "5. Clear All Expenses\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        /* Add Expense Menu */

        if (choice == 1)
        {
            if (count < MAX)
            {
                cout << "Enter expense name: ";
                cin >> categories[count];

                cout << "Enter amount: Rs. ";
                cin >> amounts[count];

                count++;

                cout << ">> Expense added! Total expenses: " << count << endl;
            }
            else
            {
                cout << "[ERROR] Maximum expense limit reached! Cannot add more expenses.\n";
            }
        }

        /* View All Expenses Menu */
        else if (choice == 2)
        {
            if (count == 0)
            {
                cout << "No expenses added yet!\n";
            }
            else
            {
                cout << "\n--- Your Expenses ---\n";
                for (int i = 0; i < count; i++)
                {
                    cout << i + 1 << ". " << categories[i] << " : Rs. " << amounts[i] << endl;
                }
            }
        }

        /* Show Total & Savings Menu */
        else if (choice == 3)
        {
            // cout << "Option 3 selected - Total & Savings\n";
            if (choice == 3)
            {
                float total = 0;
                for (int i = 0; i < count; i++)
                {
                    total += amounts[i];
                }
                float savings = pocketMoney - total;

                cout << "\n----- Total & Savings -----\n";
                cout << "Pocket Money: Rs. " << pocketMoney << endl;
                cout << "Total Expenses: Rs. " << total << endl;
                cout << "Savings: Rs. " << savings << endl;

                if (savings < 0)
                {
                    cout << "Warning: You have overspent! Savings are negative.\n";
                }
            }
        }

        /* Investment Suggestion Menu */

        else if (choice == 4)
        {
            // cout << "Option 4 selected - Investment Suggestion\n";
            float total = 0;
            for (int i = 0; i < count; i++)
            {
                total += amounts[i];
            }

            float savings = pocketMoney - total;

            cout << "\n----- Investment Suggestion -----\n";

            if (savings <= 0)
            {
                cout << "You have no savings. Try to reduce your expenses first.\n";
            }
            else if (savings < 1000)
            {
                cout << "You have Rs. " << savings << " as savings.\n";
                cout << "Suggestion: Keep it in JazzCash/EasyPaisa savings.\n";
            }
            else if (savings < 5000)
            {
                cout << "You have Rs. " << savings << " as savings.\n";
                cout << "Suggestion: Open a bank savings account (student account).\n";
            }
            else if (savings < 15000)
            {
                cout << "You have Rs. " << savings << " as savings.\n";
                cout << "Suggestion: Bank savings account + monthly saving scheme.\n";
            }
            else
            {
                cout << "You have Rs. " << savings << " as savings.\n";
                cout << "Suggestion: Bank savings + National Savings Certificate.\n";
            }
        }

        else if (choice == 5)
        {
            if (count == 0)
            {
                cout << "No expenses to clear.\n";
            }
            else
            {
                count = 0;
                cout << "All expenses cleared successfully.\n";
            }
        }

        else if (choice == 6)
        {
            // Total and Savings Calculation
            float total = 0;
            for (int i = 0; i < count; i++)
            {
                total += amounts[i];
            }
            float savings = pocketMoney - total;

            cout << "\n=========================================\n";
            cout << "           FINAL SUMMARY\n";
            cout << "=========================================\n";

            // Poori list
            if (count == 0)
            {
                cout << "  No expenses were added.\n";
            }
            else
            {
                cout << "  --- Your Expenses ---\n";
                for (int i = 0; i < count; i++)
                {
                    cout << "  " << i + 1 << ". " << categories[i]
                         << " : Rs. " << amounts[i] << endl;
                }
            }

            cout << "-----------------------------------------\n";
            cout << "  Pocket Money : Rs. " << pocketMoney << endl;
            cout << "  Total Expense: Rs. " << total << endl;
            cout << "  Savings      : Rs. " << savings << endl;
            cout << "-----------------------------------------\n";

            // Status
            if (savings < 0)
            {
                cout << "  Status: OVERSPENT! Try to save more next month.\n";
            }
            else
            {
                cout << "  Status: Good job! You saved Rs. " << savings << ".\n";
            }

            cout << "=========================================\n";
            cout << "              Exiting...\n";
            cout << "=========================================\n";
        }

    } while (choice != 6);

    return 0;
}