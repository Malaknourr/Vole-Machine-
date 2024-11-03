//
// Created by MALAK on 10/28/2024.
//

#ifndef CONTROL_UNIT_H
#define CONTROL_UNIT_H
#include<bits/stdc++.h>
#include"CPU.h"
#include "Register.h"
#include "ALU.h"
#include <bits/stdc++.h>
#include "Memory.h"
using namespace std;

/*
class Control_Unit {
    char Case;
public:
    Control_Unit() ;

};
*/


class Control_Unit {
    ALU alu;
public:

    static void opcode_checker(string instruction, Register &R, Memory &M, int &PC) {
        char op_code = instruction[0];  // Extracting the first character as the opcode

        switch (op_code) {
            case '1':
                cout<<"loaded from memory to register"<<endl;
                load(instruction, R, M);
            break;
            case '2':
                cout<<"loaded from register to memory"<<endl;
                store(instruction, R, M);
            break;
            case '3':
                cout<<"loaded memory address to register"<<endl;
                load_add(instruction, R);
            break;
            case '4':
                cout<<"Copied from register to another one"<<endl;
                copy(instruction, R);
            break;
            case '5':
                cout<<"Added two registers"<<endl;
                Add_content(instruction, R);
            break;
            case '6':
                cout<<"Added two float registers"<<endl;
                Float_Add_content(instruction, R);
            break;
            case '7':
                cout<<"Ored two registers"<<endl;
                Or_content(instruction, R);
            break;
            case '8':
                cout<<"Anded two registers"<<endl;
                And_content(instruction, R);
            break;
            case '9':
                cout<<"Xored two registers"<<endl;
                XOR_content(instruction, R);
            break;
            case 'A':
                cout<<"Rotated"<<endl;
                Rotate_content(instruction, R);
            break;
            case 'B':
                cout<<"Jumped"<<endl;
                jump(instruction[1], instruction[2], R, PC, op_code);  // Assuming jump uses parts of the instruction
            break;
            case 'C':
                if(instruction=="C000") {
                    cout << "Exited successfully" << endl;
                    exit(0);
                }
                // Placeholder for future implementation
            break;
            default:
                cout << "Invalid opcode!" << endl;  // Handle invalid opcodes
        }
    }

    
    //Function 1
    static void load(string instruction , Register &R , Memory &M) {
        int m_idx = stoi(ALU::HexToDec(instruction.substr(2,4)));
        string value = M.get(m_idx);
        char idxReg = instruction[1];
        R.setRegister(idxReg-'0', value);
    }
    //Function 2
    static void store(string instruction , Register &R , Memory &M) {

        int m_idx = stoi(ALU::HexToDec(instruction.substr(2,4)));
        char idxReg = instruction[1];
        string value = R.getRegister(idxReg-'0');
        M.set(m_idx, value);
    }
    //Function 3
    static void load_add(string instruction ,Register &R ) {
        string value = instruction.substr(2,4);
        char idxReg = instruction[1];

        R.setRegister(idxReg-'0', value);
    }
    //Function 4
    static void copy(string instruction , Register &R) {
        char idxReg1 = instruction[2];
        char idxReg2 = instruction[3];
        R.setRegister(idxReg2-'0', R.getRegister(idxReg1-'0'));
    }
    //Function 5
    static void Add_content(string instruction , Register &R) {
        R.setRegister(instruction[1]-'0', ALU::AddBinary(R.getRegister(instruction[2]-'0'), R.getRegister(instruction[3]-'0')));
    }
    //Function 6
    static void Float_Add_content(string instruction , Register &R) {
       R.setRegister(instruction[1]-'0', ALU::hexAdditionAndCustomFloat(R.getRegister(instruction[2]-'0'), R.getRegister(instruction[3]-'0')));
    }
    //Function 7
    static void Or_content(string instruction , Register &R) {
        R.setRegister(instruction[1]-'0', ALU::orTwoNums(R.getRegister(instruction[2]-'0'), R.getRegister(instruction[3]-'0')) );
    }
    //Function 8
    static void And_content(string instruction , Register &R) {
        R.setRegister(instruction[1]-'0', ALU::andTwoNums(R.getRegister(instruction[2]-'0'), R.getRegister(instruction[3]-'0')) );
    }
    //Function 9
    static void XOR_content(string instruction , Register &R) {
        R.setRegister(instruction[1]-'0', ALU::xorTwoNums(R.getRegister(instruction[2]-'0'), R.getRegister(instruction[3]-'0')) );
    }
    //Function A
    static void Rotate_content(string instruction , Register &R) {
        R.setRegister(instruction[1]-'0', ALU::xorTwoNums(R.getRegister(instruction[2]-'0'), R.getRegister(instruction[3]-'0')) );
    }
    //Function B
    static void jump(char idxReg , char idxMem, Register &R , int &PC , char op_code) {
        cout<<"Not Implemented"<<endl;
    }
    //Function C


};


#endif //CONTROL_UNIT_H
