
# Push_Swap Project

## Overview

The Push_Swap project is a challenging and educational algorithm project focused on sorting data on a stack with a limited set of instructions. The primary goal is to sort integers in ascending order with the lowest possible number of actions, requiring efficient use of various sorting algorithms.

### Key Features

- **Data Sorting:** Efficiently sorts data on a stack using a predefined set of instructions.
- **Algorithmic Complexity:** Implements and optimizes different sorting algorithms, focusing on their operational complexity.

## How it Works

The project involves two stacks, `a` and `b`, and a set of operations to manipulate these stacks. Initially, stack `a` contains a random set of integers, and stack `b` is empty. The objective is to sort the numbers in stack `a` in ascending order.

### Operations

- `sa (swap a)`: Swap the first two elements at the top of stack `a`.
- `sb (swap b)`: Swap the first two elements at the top of stack `b`.
- `ss`: Perform `sa` and `sb` simultaneously.
- `pa (push a)`: Move the top element from stack `b` to stack `a`.
- `pb (push b)`: Move the top element from stack `a` to stack `b`.
- `ra (rotate a)`: Shift all elements of stack `a` up by one position.
- `rb (rotate b)`: Shift all elements of stack `b` up by one position.
- `rr`: Perform `ra` and `rb` simultaneously.
- `rra (reverse rotate a)`: Shift all elements of stack `a` down by one position.
- `rrb (reverse rotate b)`: Shift all elements of stack `b` down by one position.
- `rrr`: Perform `rra` and `rrb` simultaneously.

## Installation

1. Clone the repository: `git clone [URL]`
2. Change to the directory: `cd push_swap`
3. Compile the project: `make`

## Usage

Run the program with a list of integers:

```bash
./push_swap [list of integers]
```

The program will output the operations performed to sort the integers.

## Example

```bash
./push_swap 2 1 3 6 5 8
```

Output:

```
sa
pb
pb
pb
sa
pa
pa
pa
```

