// CPU.h

#ifndef CPU_H
#define CPU_H

#include "Register.h"
#include "ALU.h"
#include <bits/stdc++.h>
#include "Control_Unit.h"

#include "Memory.h"

using namespace std;

class CPU {
    Register reg;
    Memory memory;
    ALU alu;

    int PC = 0;                    // Program Counter
    string IR;                     // Instruction Register

public:
    CPU() : reg(), memory(), alu(), PC(0), IR("") {};

    // Load next instruction from the input file into IR and increment PC
    void loadNextInstruction(ifstream& inputFile) {
        // Clear any previous instructions
        IR.clear();

        // Read characters from the file
        char ch;
        while (inputFile.get(ch)) {
            // Skip any spaces or newlines
            if (std::isspace(ch)) {
                continue;
            }

            // Append character to IR
            IR += ch;

            // If we have 4 characters, process the instruction
            if (IR.length() == 4) {
                cout << "Instruction loaded into IR: " << IR << endl;

                // Increment the PC to point to the next instruction
                PC += 4; // Increment PC by 4 since each instruction is 4 characters

                // Here you can call any method to process the instruction if needed
                runNextStep();
                // Reset IR for the next instruction
                IR.clear();
            }
        }

        // Handle any remaining characters in IR (if the file doesn't end on a complete instruction)
        if (!IR.empty()) {
            cout << "Incomplete instruction at end of file: " << IR << endl;
        }

        cout << "End of input file reached." << endl;
    }
    string runNextStep() {
        // Assuming IR holds a valid instruction in hex format
        if (!IR.empty()) {
            int address = stoi(ALU::HexToDec(IR.substr(2, 4))); // Convert hex address
            string value = memory.get(address);                 // Retrieve value from memory
            return value;
        } else {
            cout << "No instruction loaded in IR." << endl;
            return "";
        }
    }

};

#endif // CPU_H
