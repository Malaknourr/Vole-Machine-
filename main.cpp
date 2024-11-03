#include <iostream>
#include "Register.h"
#include "ALU.h"
#include <bits/stdc++.h>
#include "Control_Unit.h"
#include "Memory.h"
//#include "CPU.h"
using namespace std;
#include "Register.h"
#include "ALU.h"
#include<bits/stdc++.h>

string toUpperCase(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

int main() {

    Control_Unit Cu;
    Register Reg;
    Memory Mem;
    ALU alu;

    int index = stoi(alu.HexToDec("E0"));
    Mem.set( index , "32");

    Reg.setRegister(8,"F3");
    Reg.setRegister(9,"A9");

    string instruction;
    string instruction1;
    int  PC;
    while(true) {
        cout<<endl<<endl<<"Please enter the instruction:";
        cin>>instruction;
        instruction1 = toUpperCase(instruction); ;
        Cu.opcode_checker(instruction1 ,Reg ,Mem ,PC );
        Reg.display_registers();
        Mem.display_memory();
    }
}