// Register.h

#ifndef REGISTER_H
#define REGISTER_H
#include <iomanip>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Register {
    int size = 16;
    vector<string> Registers;

public:
    Register() : size(16), Registers(16, "00") {}

    string getRegister(int index) const {
        return Registers[index];
    }

    void setRegister(int index ,  const string &value) {
        if (index >= 0 && index < size - 1) { // Check for valid index
            Registers[index] = value;

        }
    }

    void display_registers() const {
        for (int i = 0; i < size; ++i) {
            cout << "Register#" << i << " :" << getRegister(i) << endl;
        }
    }


};

#endif //REGISTER_H
