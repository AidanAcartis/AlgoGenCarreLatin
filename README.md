# Latin Square Generator and Permutation Explorer (C)

This project generates **Latin squares** from permutations of an initial row, and explores all possible permutations using optimized loops.

The program is written in **C**, and is split into several modules:

- `main.c`
- `boucles.c`
- `permutation.c`
- `utils.c`
- header files: `permutation.h`, `boucles.h`, `utils.h`

---

## 📌 Project Objective

- Generate a **Latin square** of order `n` from an initial permutation.
- Iterate through all possible permutations of the first row.
- For each permutation, build the corresponding Latin square.
- Display the number of generated permutations.

---

## 🧠 Mathematical Concepts

### 1. **Factorial (n!)**

The number of permutations of a set with `n` elements is:

\[
n! = n \times (n-1) \times (n-2) \times \dots \times 2 \times 1
\]

The function `Factoriel(n)` computes this value:

```c
int Factoriel(int a)
{
    int F = 1;
    for(int i = 2; i <= a; i++)
        F *= i;
    return F;
}
````

---

### 2. **Half Factorial (n!/2)**

To optimize the search and reduce the number of iterations, the program uses:

[
\frac{n!}{2}
]

The function `FactorielSur2(n)` computes `n!/2`:

```c
int FactorielSur2(int a)
{
    if (a <= 1) return 1;

    int F = 1;
    for(int i = 2; i <= a; i++)
        F *= i;

    return F / 2;
}
```

---

### 3. **Latin Square**

A **Latin square** of order `n` is an `n × n` matrix such that:

* Each row contains numbers from `1` to `n` without repetition.
* Each column contains numbers from `1` to `n` without repetition.

In this project, the Latin square is built from a base row `t`:

[
\text{Square}[i][j] = t[(i + j) \bmod n]
]

This creates a **cyclic Latin square**, which is one of the standard constructions.

---

### 4. **Permutations by Circular Shifts**

The permutation function `FonctionPermut()` performs a **circular shift** of the array `t`.

Given a row:

```
t = [1, 2, 3, 4]
```

With `tour = 1`, `permut = 4`:

```
T = [4, 1, 2, 3]
```

The function ensures the permutation respects bounds and stays within the array.

---

## 📁 File Structure

### `main.c`

* Reads the dimension `n`
* Creates and initializes the base row `t`
* Creates the `Tour` and `Permut` arrays
* Prints the expected number of permutations (`n!`)
* Calls `BouclePermut()`

### `boucles.c`

Contains:

* `BouclePermut()`

  * Iterates through permutations of the first row
  * Builds Latin squares
  * Calls `BouclePermutCarre()`

* `BouclePermutCarre()`

  * Iterates through permutations of the Latin square itself

* `Echange()`

  * Copies one matrix into another

### `permutation.c`

Contains:

* `FonctionPermut()`

  * Applies a circular permutation on the row
* `DefinirTableaut()`

  * Defines the initial base row `[1..n]`

### `utils.c`

Contains:

* Display functions (`afficheTableau`, `afficheTableauPermutee`)
* `Factoriel()` and `FactorielSur2()`

---

## 🧪 Example Execution

Example input:

```
Enter the dimension: 3
```

Expected output:

```
1   2   3
We should obtain 6 permutations
...
```

---

## ⚙️ Compilation

```bash
gcc main.c boucles.c permutation.c utils.c -o main
```

Run:

```bash
./main
```

---

## 🔍 Notes

* The program uses `FactorielSur2()` for optimization and to avoid exploring symmetric permutations.
* It generates cyclic Latin squares and then permutes rows/columns using the permutation logic.

---

## 🚀 Possible Improvements

* Handle edge cases (`n = 1`, `n = 2`) more gracefully.
* Avoid duplicates by detecting isomorphic Latin squares.
* Improve performance for larger `n` using better permutation algorithms.

---

## 📝 Author

A C project for generating Latin squares and exploring permutations.

