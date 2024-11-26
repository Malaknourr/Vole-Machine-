# Vole Machine Simulator

This repository contains a simulation of a **Vole Machine**, a simple virtual machine that consists of multiple components including memory, registers, and an instruction set. The Vole Machine emulator supports basic operations such as **LOAD**, **STORE**, and other control flow instructions, and simulates the execution of machine-level code.

## Features

- **Memory Simulator**: Memory is modeled using an array of hexadecimal values, where each memory cell holds a 4-digit hexadecimal instruction.
- **Registers**: The Vole Machine includes several registers (e.g., Program Counter, Instruction Register) to manage the flow of execution.
- **Instruction Set**: The machine supports a variety of operations like `LOAD`, `STORE`, `ADD`, `JUMP`, and `HALT` with corresponding opcodes.
- **Control Flow**: The Vole Machine follows a simple fetch-execute cycle, updating registers and memory as it executes instructions.

## Components

- **Memory**: A simulated memory space represented as a series of hexadecimal values, with each memory address holding a 4-digit instruction.
- **Registers**: The machine includes various registers (e.g., `PC` for Program Counter, `IR` for Instruction Register) to store the current state.
- **Instruction Set**: Instructions are encoded as 4-digit hexadecimal values, with specific opcodes to control the machine's behavior.
