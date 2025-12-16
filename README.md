# Sudoku Generator Project
## Project Overview

This project implements a Sudoku generator in C that can generate Sudoku grids of any dimension `n`. The algorithm uses permutations, Latin squares, and factorial-based calculations to produce all valid arrangements of numbers in the grid while maintaining Sudoku constraints.

## Features

* Generates Sudoku grids of variable size `n × n`.
* Uses a combination of permutation logic and Latin square construction.
* Handles factorial-based calculations for generating all possible configurations.
* Includes visualization of intermediate permutations and Latin squares for debugging.

## How It Works

1. **Table Initialization**: The numbers 1 to `n` are initialized in a sequence.
2. **Permutation Function**: Generates permuted sequences for rows using a factorial-based logic.
3. **Latin Square Construction**: Each row is arranged to form a Latin square, ensuring no duplicates in rows and columns.
4. **Sudoku Grid Generation**: Combines all row permutations to produce valid Sudoku grids.
5. **Display**: Outputs the generated Sudoku grid and intermediate permutations.

## Usage

1. Compile the program:

```bash
gcc sudoku_generator.c -o sudoku_generator
```

2. Run the executable and enter the desired dimension:

```bash
./sudoku_generator
Enter dimension: 4
```

3. The program prints all generated permutations and the corresponding Sudoku grid.

## Key Functions

* `FonctionPermut()`: Generates permutations of a sequence.
* `BouclePermut()`: Loops through all permutations to create Latin squares.
* `BouclePermutCarre()`: Extends permutations to generate the full Sudoku grid.
* `Echange()`: Copies and maintains matrices for intermediate steps.
* `Factoriel()` / `FactorielSur2()`: Compute factorials for permutation counting.

## Applications

* Educational tool for learning about permutations, Latin squares, and Sudoku generation.
* Basis for building Sudoku puzzle solvers or generators with additional constraints.

## Repository Link

The full code is available at: [GitHub Link]

## Conclusion

This project demonstrates algorithmic thinking in combinatorics and matrix operations for generating valid Sudoku grids of arbitrary size. It showcases the use of permutations, factorial mathematics, and Latin square construction in C.

