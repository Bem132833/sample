#include <iostream>
#include <cmath> // For advanced math functions

using namespace std;

int main() {
    char op;
    double num1, num2, result;

    cout << "Simple Calculator Program" << endl;
    cout << "------------------------" << endl;
    cout << "Enter first number: ";
    cin >> num1;
    
    cout << "Enter operator (+, -, *, /, % for modulus, ^ for power, s for square root): ";
    cin >> op;
    
    // For operations that don't need a second number (like square root)
    if (op != 's' && op != 'S') {
        cout << "Enter second number: ";
        cin >> num2;
    }

    switch(op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Error: Division by zero!" << endl;
                return 1;
            }
            break;
        case '%':
            result = static_cast<int>(num1) % static_cast<int>(num2);
            break;
        case '^':
            result = pow(num1, num2);
            break;
        case 's':
        case 'S':
            if (num1 >= 0) {
                result = sqrt(num1);
            } else {
                cout << "Error: Square root of negative number!" << endl;
                return 1;
            }
            break;
        default:
            cout << "Error: Invalid operator!" << endl;
            return 1;
    }

    cout << "Result: " << result << endl;
    
    return 0;
}