/*
 * Simple Console Calculator in C++
 * -------------------------------
 * Uses only the iostream library
 * All functions return values instead of void
   By : Ahmed Majid Madlol - A
 */

#include <iostream>

using namespace std;

// Function declarations
int showMenu();
double doAddition();
double doSubtraction();
double doMultiplication();
double doDivision();
int doModulus();
double doPower();
long doFactorial();
bool clearInputBuffer();

int main() {
    int choice;
    bool running = true;
    
    // Main program loop
    while (running) {
        // Display interface
        cout << "==============================\n";
        cout << "    Simple Console Calculator  \n";
        cout << "==============================\n";
        
        choice = showMenu();
        
        // Execute selected operation
        switch (choice) {
            case 1:
                doAddition();
                break;
            case 2:
                doSubtraction();
                break;
            case 3:
                doMultiplication();
                break;
            case 4:
                doDivision();
                break;
            case 5:
                doModulus();
                break;
            case 6:
                doPower();
                break;
            case 7:
                doFactorial();
                break;
            case 0:
                running = false;
                cout << "Thank you for using the calculator! Goodbye!\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
        
        // Wait for Enter key before continuing
        if (running) {
            cout << "\nPress Enter to continue...";
            clearInputBuffer();
            cin.get();
        }
    }
    
    return 0;
}

// Display menu of available operations and return user's choice
int showMenu() {
    int choice = 0;
    
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "6. Power\n";
    cout << "7. Factorial (!)\n";
    cout << "0. Exit\n";
    
    cout << "Your choice: ";
    cin >> choice;
    
    // Validate input
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return -1;
    }
    
    return choice;
}

// Clear input buffer, returns true if successful
bool clearInputBuffer() {
    cin.ignore(10000, '\n');
    return true;
}

// Addition operation - returns the sum
double doAddition() {
    double num1, num2, result;
    
    cout << "\n-- Addition Operation --\n";
    cout << "Enter first number: ";
    cin >> num1;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    cout << "Enter second number: ";
    cin >> num2;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    result = num1 + num2;
    cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
    return result;
}

// Subtraction operation - returns the difference
double doSubtraction() {
    double num1, num2, result;
    
    cout << "\n-- Subtraction Operation --\n";
    cout << "Enter first number: ";
    cin >> num1;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    cout << "Enter second number: ";
    cin >> num2;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    result = num1 - num2;
    cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
    return result;
}

// Multiplication operation - returns the product
double doMultiplication() {
    double num1, num2, result;
    
    cout << "\n-- Multiplication Operation --\n";
    cout << "Enter first number: ";
    cin >> num1;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    cout << "Enter second number: ";
    cin >> num2;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    result = num1 * num2;
    cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
    return result;
}

// Division operation - returns the quotient
double doDivision() {
    double num1, num2, result;
    
    cout << "\n-- Division Operation --\n";
    cout << "Enter numerator (first number): ";
    cin >> num1;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    cout << "Enter denominator (second number): ";
    cin >> num2;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    if (num2 == 0) {
        cout << "Error: Cannot divide by zero!\n";
        return 0;
    }
    
    result = num1 / num2;
    cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
    return result;
}

// Modulus operation - returns the remainder
int doModulus() {
    int num1, num2, result;
    
    cout << "\n-- Modulus Operation --\n";
    cout << "Enter first number (integer): ";
    cin >> num1;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    cout << "Enter second number (integer): ";
    cin >> num2;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    if (num2 == 0) {
        cout << "Error: Cannot find modulus with zero divisor!\n";
        return 0;
    }
    
    result = num1 % num2;
    cout << "Result: " << num1 << " % " << num2 << " = " << result << "\n";
    return result;
}

// Power operation - returns base raised to exponent
double doPower() {
    double base, result = 1.0;
    int exponent;
    
    cout << "\n-- Power Operation --\n";
    cout << "Enter base: ";
    cin >> base;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    cout << "Enter exponent: ";
    cin >> exponent;
    
    if (cin.fail()) {
        cout << "Invalid input!\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    // Handle negative exponents
    bool isNegative = false;
    if (exponent < 0) {
        isNegative = true;
        exponent = -exponent;
    }
    
    // Calculate power using a loop
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    
    // Handle negative exponent case
    if (isNegative) {
        if (result != 0) {
            result = 1.0 / result;
        } else {
            cout << "Error: Cannot divide 1 by 0 (negative exponent with zero base)!\n";
            return 0;
        }
    }
    
    cout << "Result: " << base << " ^ " << (isNegative ? -exponent : exponent) << " = " << result << "\n";
    return result;
}

// Factorial operation - returns n!
long doFactorial() {
    int num;
    long result = 1;
    
    cout << "\n-- Factorial Operation --\n";
    cout << "Enter a positive integer: ";
    cin >> num;
    
    if (cin.fail() || num < 0) {
        cout << "Invalid input! Must be a positive integer.\n";
        cin.clear();
        clearInputBuffer();
        return 0;
    }
    
    if (num > 12) {
        cout << "Warning: Number is large and may exceed the type limit.\n";
    }
    
    // Calculate factorial
    for (int i = 1; i <= num; i++) {
        result *= i;
    }
    
    cout << "Result: " << num << "! = " << result << "\n";
    return result;
}
