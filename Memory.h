// Memory.h

#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Memory {
    vector<string> memory;
    int size=256;

public:
    Memory() : size(256), memory(256, "00") {}

    void set(int index, const string &value) {
        if (index >= 0 && index < size) { // Check for valid index
            memory[index] = value;
        }
    }

    string get(int index) const {
        if (index >= 0 && index < size) { // Check for valid index
            return memory[index];
        }
        return ""; // Return an empty string if index is out of bounds
    }

    void display_memory() {
        cout << endl << "Memory Display" << endl;
        for (int i = 0; i < size; i++) {
            if(i%16==0 && i != 0 ) {
                cout<<endl;
            }
            cout<<memory[i]<<" ";
        }
    }
};

#endif //MEMORY_H
