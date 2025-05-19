# Simple Console Calculator in C++

**Author: Ahmed Majid Madlool**

## Project Overview

This project implements a simple console-based calculator using C++. The calculator provides basic arithmetic operations as well as more advanced mathematical functions, all while using only the standard iostream library. The program is designed to be clear, robust, and user-friendly.

## Features

- Menu-driven interface
- Basic operations: addition, subtraction, multiplication, division
- Advanced operations: modulus, power calculation, factorial
- Input validation and error handling
- Functions that return values instead of using void
- No external dependencies beyond the standard iostream library

## Code Structure & Explanation

### Function Declarations

```cpp
int showMenu();
double doAddition();
double doSubtraction();
double doMultiplication();
double doDivision();
int doModulus();
double doPower();
long doFactorial();
bool clearInputBuffer();
```

All functions return values rather than using void, which allows for potential reuse of calculation results in more advanced implementations.

### Main Function

```cpp
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
```

The main function controls the program flow using a while loop that continues until the user chooses to exit. It displays a header, shows the menu, processes the user's choice using a switch statement, and waits for the user to press Enter before continuing.

### Menu Display Function

```cpp
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
```

This function displays the menu options and captures the user's choice. It returns the chosen operation number, or -1 if the input is invalid. The input validation ensures that the program won't crash if the user enters non-numeric data.

### Input Buffer Clearing Function

```cpp
bool clearInputBuffer() {
    cin.ignore(10000, '\n');
    return true;
}
```

This utility function clears the input buffer, which is important for handling input errors and ensuring that subsequent inputs work correctly. It returns true to indicate successful completion.

### Basic Arithmetic Operations

Each operation function follows a consistent pattern:
1. Display operation header
2. Request and validate input values
3. Perform calculation
4. Display result
5. Return the calculated value

For example, the addition function:

```cpp
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
```

The subtraction, multiplication, and division functions follow the same pattern, with division adding a check to prevent division by zero.

### Modulus Operation

```cpp
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
```

The modulus operation calculates the remainder after division. It uses integer values instead of doubles since modulus is only defined for integers. It also includes validation to prevent division by zero.

### Power Operation

```cpp
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
```

The power function calculates base raised to exponent. Instead of using the pow() function from cmath, it implements the calculation manually using a loop. This approach demonstrates how mathematical operations can be performed using basic programming constructs. The function handles negative exponents by taking the reciprocal of the result.

### Factorial Operation

```cpp
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
```

The factorial function calculates n! (n factorial), which is the product of all positive integers less than or equal to n. It includes validation to ensure the input is non-negative and warns about potential overflow for large inputs.

## Key Programming Concepts

### 1. Input Validation

The program checks for invalid input throughout:
- Verifies that numeric inputs are actually numbers
- Clears error flags and the input buffer when errors occur
- Provides user feedback for invalid inputs
- Prevents calculation with invalid values

### 2. Error Handling

Special cases are handled to prevent program crashes:
- Division by zero
- Modulus with zero divisor
- Negative exponents with zero base
- Negative or excessively large factorial inputs

### 3. Program Flow Control

The program uses various control structures:
- While loop for the main program loop
- Switch statement for menu selection
- For loops for calculations
- If-else statements for validation and error handling

### 4. Function Design

Each function has:
- A clear, single responsibility
- Appropriate return type for its purpose
- Consistent structure for user interaction
- Input validation and error handling

## How to Compile and Run

1. Ensure you have a C++ compiler installed (like g++, clang++, or MSVC)
2. Compile the code:
   ```
   g++ calculator.cpp -o calculator
   ```
3. Run the program:
   ```
   ./calculator
   ```
   (On Windows, use `calculator.exe`)

## Potential Improvements

- Memory function to store previous results
- Support for more complex expressions
- Additional mathematical functions (trigonometry, logarithms)
- Improved user interface
- Handling for larger numbers with appropriate data types

## License

This project is open source and available under the MIT License.

---

© 2025 Ahmed Majid Madlool
