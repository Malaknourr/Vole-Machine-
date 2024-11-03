//
// Created by MALAK on 10/28/2024.
//

#ifndef ALU_H
#define ALU_H

#include <iostream>
#include <string>
#include <bitset>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

struct CustomFloat {
    int sign;      // 1 bit for sign
    int exponent;  // 3 bits for exponent
    int mantissa;  // 4 bits for mantissa
};

class ALU {
public:
    static bool checkValid(string hexNum) {
        for (char& digit : hexNum) {
            if (digit >= '0' && digit <= '9' || digit >= 'A' && digit <= 'F') {
                return true;
            }
        }
        return false; // Return false if any character is invalid
    }

    static string integerToBinary(int integerPart) {
        string binary = "";
        if (integerPart == 0) {
            return "0";
        }
        while (integerPart > 0) {
            binary = to_string(integerPart % 2) + binary;
            integerPart /= 2;
        }
        return binary;
    }

    static string fractionalToBinary(double fractionalPart) {
        string binary = "";
        while (fractionalPart > 0) {
            fractionalPart *= 2;
            int bit = static_cast<int>(fractionalPart);
            if (bit == 1) {
                binary += "1";
                fractionalPart -= bit;
            } else {
                binary += "0";
            }
        }
        return binary;
    }

    static string floatToBinary(double number) {
        // Separate integer and fractional parts
        int integerPart = static_cast<int>(number);
        double fractionalPart = number - integerPart;

        // Convert both parts to binary
        string binary = integerToBinary(integerPart) + ".";
        binary += fractionalToBinary(fractionalPart);

        return binary;
    }

    static string HexToDec(const string& hexNum) {
        int decimalValue = stoi(hexNum, nullptr, 16); // Convert hex string to decimal integer
        return to_string(decimalValue);
    }

    static string BinToDec(const string& binNum) {
        bitset<32> bits(binNum); // Create a bitset from binary string
        int decimalValue = bits.to_ulong(); // Convert to unsigned long (integer)
        return to_string(decimalValue);
    }

    static string DecToHex(const string& num) {
        int decNum = stoi(num); // Convert decimal string to integer
        stringstream ss;
        ss << hex << uppercase << decNum; // Convert integer to hexadecimal string in uppercase
        return ss.str();
    }

    static string AddBinary(const string& Num1, const string& Num2) {
        string decNum1 = HexToDec(Num1); // Convert hexadecimal to decimal integer
        string decNum2 = HexToDec(Num2); // Convert hexadecimal to decimal integer

        int sum = stoi(decNum1) + stoi(decNum2); // Add the two decimal integers

        // Check if the sum is negative
        if (sum < 0) {
            // Use two's complement representation for the negative number
            int positiveSum = abs(sum); // Get the absolute value of sum
            bitset<9> binarySum(positiveSum); // Create binary representation for positive part
            string result = binarySum.to_string();

            // Convert to two's complement manually
            for (char& bit : result) {
                bit = (bit == '0') ? '1' : '0'; // Invert bits
            }

            // Add 1 to get two's complement
            int carry = 1;
            for (int i = result.size() - 1; i >= 0; --i) {
                if (result[i] == '1' && carry == 1) {
                    result[i] = '0';
                } else if (carry == 1) {
                    result[i] = '1';
                    carry = 0;
                }
            }
            return DecToHex(BinToDec(result));
        } else {
            // For non-negative sum, use regular bitset conversion
            bitset<9> binarySum(sum); // 9-bit to cover potential bit overflow cases
            return DecToHex(BinToDec(binarySum.to_string()));
        }
    }

    static string orTwoNums(const string& Num1, const string& Num2) {
        int decNum1 = stoi(HexToDec(Num1));
        int decNum2 = stoi(HexToDec(Num2));
        int res = decNum1 | decNum2; // Perform OR operation directly on decimal
        return DecToHex(to_string(res)); // Return result as a binary string
    }

    static string andTwoNums(const string& Num1, const string& Num2) {
        int decNum1 = stoi(HexToDec(Num1));
        int decNum2 = stoi(HexToDec(Num2));
        int res = decNum1 & decNum2; // Perform AND operation directly on decimal
        return DecToHex(to_string(res)); // Return result as a binary string
    }

    static string xorTwoNums(const string& Num1, const string& Num2) {
        int decNum1 = stoi(HexToDec(Num1));
        int decNum2 = stoi(HexToDec(Num2));
        int res = decNum1 ^ decNum2; // Perform XOR operation directly on decimal
        return DecToHex(to_string(res)); // Return result as a binary string
    }

    
};

#endif // ALU_H/=