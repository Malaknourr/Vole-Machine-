# Vole Machine Simulator

## Features

- **Memory Simulation**: Implements a memory model where each memory cell holds a 4-digit hexadecimal instruction.
- **Register System**: Includes essential registers such as the **Program Counter (PC)**, **Instruction Register (IR)**, and general-purpose registers.
- **Instruction Set**: Supports fundamental machine-level operations, including arithmetic, data transfer, and control flow.
- **Execution Cycle**: Implements the Fetch-Decode-Execute cycle to process machine instructions.
- **Interactive CLI**: Allows users to manually input instructions, load programs, and execute them step by step.
- **Error Handling**: Detects and handles invalid instructions, memory overflows, and illegal operations.

## System Components

### 1. Memory
- A fixed-size memory array storing **4-digit hexadecimal** values.
- Each instruction is stored as a separate memory entry.
- Memory is indexed in hexadecimal format.

### 2. Registers
- **Program Counter (PC):** Points to the next instruction to execute.
- **Instruction Register (IR):** Holds the currently executing instruction.
- **General Registers:** Used for arithmetic and logical operations.

### 3. Instruction Set Architecture

| Opcode  | Mnemonic | Description                         |
|---------|---------|---------------------------------|
| `10XX`  | `LOAD`  | Load value from memory into register |
| `20XX`  | `STORE` | Store value from register into memory |
| `30XX`  | `ADD`   | Add memory value to register |
| `40XX`  | `SUB`   | Subtract memory value from register |
| `50XX`  | `JUMP`  | Jump to a memory location |
| `60XX`  | `JZ`    | Jump if zero flag is set |
| `70XX`  | `JN`    | Jump if negative flag is set |
| `C000`  | `HALT`  | Stop execution |



Upon launching, the simulator presents an interactive menu:

```text
Enter your choice:
(A) Load Instructions from File
(B) Enter Instructions Manually
(C) Display Memory and Registers
(D) Execute Instructions
(E) Exit
```

### Example Execution

#### Manually Entering Instructions
```
> B
Enter instructions (4-digit hex, type 'C000' to stop):
> 1001
> 2002
> 3003
> C000
```

#### Executing Instructions
```
> D
Executing...
IR: 1001 | PC: 0001
IR: 2002 | PC: 0002
IR: 3003 | PC: 0003
Execution halted.
```

### Debugging and Inspection
To display the current state of memory and registers:
```
> C
Memory Dump:
0000: [1001]  0001: [2002]  0002: [3003]  0003: [C000]

Registers:
PC: 0003, IR: C000
```

## Contributing
Contributions are welcome! Feel free to fork this repository, submit issues, or open pull requests.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

