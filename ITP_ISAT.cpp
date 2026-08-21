#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <cctype>
using namespace std;

string decimalToBinary(int decimal) {
    if(decimal == 0) {
        return "0";
    }
    string binary = "";
    int num = decimal;
    while(num > 0) {
        binary = (num % 2 == 0 ? "0" : "1") + binary;
        num /= 2;  
    }
    return binary;
}
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 0;
    for(int i = binary.length() - 1; i >= 0; i--) {
        if(binary[i] == '1') {
            decimal += pow(2, power);
        }else if(binary[i] != '0') {
            cout << "Invalid binary number." << endl;
            return -1;
        }
        power++;
    }
    return decimal;
}
string decimalToHexadecimal(int decimal) {
    if(decimal == 0) {
        return "0";
    }

    string hexadecimal = "";
    char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int num = decimal;

    while (num > 0) {
        hexadecimal = hexDigits[num % 16] + hexadecimal;
        num /= 16;
    }

    return hexadecimal;
}

int hexadecimalToDecimal(string hexadecimal) {
    int decimal = 0;
    int power = 0;

    transform(hexadecimal.begin(), hexadecimal.end(), hexadecimal.begin(), ::toupper);

    for (int i = hexadecimal.length() - 1; i >= 0; i--) {
        int hexValue;
        if (hexadecimal[i] >= '0' && hexadecimal[i] <= '9') {
            hexValue = hexadecimal[i] - '0';
        } else if (hexadecimal[i] >= 'A' && hexadecimal[i] <= 'F') {
            hexValue = hexadecimal[i] - 'A' + 10;
        } else {
            cout << "Invalid hexadecimal number." << endl;
            return -1;
        }
        decimal += hexValue * pow(16, power);
        power++;
    }
    return decimal;
}
void demo(){
    srand(time(0));
    int randomNum = rand()%100;
    cout << "Generated random integer: " << randomNum << endl;
    cout << "binary representation: " << decimalToBinary(randomNum) << endl;
    cout << "hexadecimal representation: " << decimalToHexadecimal(randomNum) << endl;

}
void displayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Convert Decimal to Binary" << endl;
    cout << "2. Convert Decimal to Hexadecimal" << endl;
    cout << "3. Convert Binary to Decimal" << endl;
    cout << "4. Convert Hexadecimal to Decimal" << endl;
    cout << "5. Demo (Generate and convert a random integer)" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your choice (1-6): ";
}

bool readDecimalInput(int &decimal, const string &prompt) {
    cout << prompt;

    if (!(cin >> decimal)) {
        cout << "Invalid decimal number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    if (decimal < 0) {
        cout << "Decimal number must be non-negative." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return false;
    }

    return true;
}

int main() {
    int choice = 0;

    do {
        displayMenu();

        string choiceInput = "";
        if (!(cin >> choiceInput)) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = 0;
            continue;
        }
        try {
            size_t idx = 0;
            int parsed = stoi(choiceInput, &idx);
            if (idx != choiceInput.length()) throw invalid_argument("extra");
            choice = parsed;
        } catch (...) {
            cout << "Invalid input. Please try again." << endl;
            choice = 0;
            continue;
        }

        // Keep the input validation and switch logic in clearly matched blocks to avoid
        // dangling control-flow issues such as an else without a corresponding if.
        switch (choice) {
            case 1: {
                int decimal = 0;
                cout << "Enter a decimal number: ";
                if (cin >> decimal) {
                    cout << "Binary representation: " << decimalToBinary(decimal) << endl;
                } else {
                    cout << "Invalid decimal number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 2: {
                int decimal = 0;
                cout << "Enter a decimal number: ";
                if (cin >> decimal) {
                    cout << "Hexadecimal representation: " << decimalToHexadecimal(decimal) << endl;
                } else {
                    cout << "Invalid decimal number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 3: {
                string binary = "";
                cout << "Enter a binary number: ";
                if (cin >> binary) {
                    int result = binaryToDecimal(binary);
                    if (result != -1) {
                        cout << "Decimal representation: " << result << endl;
                    }
                } else {
                    cout << "Invalid binary number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 4: {
                string hexadecimal = "";
                cout << "Enter a hexadecimal number: ";
                if (cin >> hexadecimal) {
                    int result = hexadecimalToDecimal(hexadecimal);
                    if (result != -1) {
                        cout << "Decimal representation: " << result << endl;
                    }
                } else {
                    cout << "Invalid hexadecimal number." << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                break;
            }
            case 5:
                demo();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } 

    return 0;
}