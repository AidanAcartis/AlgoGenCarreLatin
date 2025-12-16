# Latin Square Generator Project

**Author:** Your Name
**Date:** December 16, 2025

## Project Overview

This project implements a Latin square generator in C. A Latin square is an `n × n` grid filled with `n` different symbols (numbers in this case), each occurring exactly once in each row and column. The generator uses permutations and factorial-based logic to produce all possible Latin squares for a given dimension `n`.

## Features

* Generates Latin squares of any dimension `n`.
* Uses permutation logic to systematically explore all row arrangements.
* Builds full Latin squares from row permutations while respecting constraints.
* Includes printing of intermediate permutations for verification.

## How It Works

1. **Initialization**: Numbers from 1 to `n` are stored in an initial array.
2. **Permutation Function (`FonctionPermut`)**: Generates permuted sequences for rows.
3. **Row Looping (`BouclePermut`)**: Iterates through permutations to create all possible first rows.
4. **Latin Square Construction (`BouclePermutCarre`)**: Combines row permutations to construct complete Latin squares.
5. **Matrix Copy (`Echange`)**: Copies intermediate matrices for further permutations without losing previous states.
6. **Factorial Functions (`Factoriel` and `FactorielSur2`)**: Used for counting permutations and controlling loops.

## Usage

1. Compile the program:

```bash
gcc latin_square_generator.c -o latin_square_generator
```

2. Run the executable and enter the desired dimension:

```bash
./latin_square_generator
Enter dimension: 4
```

3. The program prints all generated permutations and the corresponding Latin squares.

## Key Functions

* `FonctionPermut()`: Generates permutations of a row.
* `BouclePermut()`: Loops through row permutations.
* `BouclePermutCarre()`: Constructs complete Latin squares from row permutations.
* `Echange()`: Maintains copies of matrices during permutation generation.
* `Factoriel()` / `FactorielSur2()`: Factorial calculations for loop management.

## Applications

* Educational tool to explore combinatorics and matrix arrangements.
* Foundation for advanced puzzle generation and Latin square-based algorithms.
* Useful in design of experiments and error-correcting codes.
  
## Conclusion

This project demonstrates algorithmic techniques for generating Latin squares using permutations and factorial logic. It highlights systematic combinatorial generation and matrix manipulation in C.


Veux‑tu que je fasse ça ?
