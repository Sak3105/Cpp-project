#include <iostream>

using namespace std;

int main() {
    double num1, num2;
    char operation;
    char continueCalc;

    do {
        // Ask the user for input
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter an operator (+, -, *, /): ";
        cin >> operation;

        cout << "Enter second number: ";
        cin >> num2;

        // Perform the calculation based on the operator
        switch (operation) {
            case '+':
                cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
                break;
            case '-':
                cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
                break;
            case '*':
                cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
                break;
            case '/':
                if (num2 != 0) {
                    cout << num1 << " / " << num2 << " = " << (num1 / num2) << endl;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                }
                break;
            default:
                cout << "Error: Invalid operator." << endl;
                break;
        }

        // Ask if the user wants to continue
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> continueCalc;

    } while (continueCalc == 'y' || continueCalc == 'Y');

    cout << "Thank you for using the calculator!" << endl;

    return 0;
}
