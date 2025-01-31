#include <iostream>
#include <string>
#include <vector>

using namespace std;

class romanType {
private:
    int integerValue;
    string romanValue;

public:
    void setIntegerValue(int value) {
        integerValue = value;
        convertToRoman();
    }

    void setRomanValue(const string& value) {
        romanValue = value;
        convertToInteger();
    }

    void convertToRoman() {
        const string romanSymbols = "IVXLCDM"; //Roman numeral symbols
        const vector<int> romanValues = {1, 5, 10, 50, 100, 500, 1000}; //integer conversion values

        int value = integerValue;
        romanValue = "";

        for (int i = romanValues.size() - 1; i >= 0; i--) {
            while (value >= romanValues[i]) { //find the largest value that fits
                romanValue += romanSymbols[i]; //append the corresponding symbol
                value -= romanValues[i]; //subtract the value
            }
        }
    }

    void convertToInteger() {
        const string romanSymbols = "IVXLCDM"; //Roman numeral symbols
        const vector<int> romanValues = {1, 5, 10, 50, 100, 500, 1000}; //integer conversion values

        int value = 0;
        int previousValue = 0;

        for (const auto& symbol : romanValue) {
            int index = romanSymbols.find(symbol); //find the index for the symbol
            int current = romanValues[index]; //get the integer value
            value += current; //add the values

            if (current > previousValue) {
                value -= 2 * previousValue; //handle subtraction of Roman numerals
            }

            previousValue = current;
        }

        integerValue = value;
    }

    void printIntegerValue() const {
        cout << "Integer value: " << integerValue << endl;
    }

    void printRomanValue() const {
        cout << "Roman value: " << romanValue << endl;
    }
};

int main() {
    romanType romanObj;

    string userInput;
    cout << "Enter a Roman numeral: ";
    cin >> userInput;
    romanObj.setRomanValue(userInput);

    int choice;
    cout << "Choose an option:\n1. Print as an Integer\n2. Print as a Roman Numeral\n";
    cin >> choice;

    if (choice == 1) {
        romanObj.printIntegerValue();
    } else if (choice == 2) {
        romanObj.printRomanValue();
    } else {
        cout << "Invalid choice." << endl;
    }

    return 0;
}