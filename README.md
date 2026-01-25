# Latin Square Generation in C

## Overview

This project implements an **algorithmic and combinatorial exploration of Latin squares of arbitrary order n**, written in **procedural C**.

The work focuses on:

* permutation generation
* construction of Latin squares
* enumeration of equivalent Latin squares via row permutations

The implementation reflects an **early-stage, non–object-oriented approach**, intentionally preserved to showcase the original reasoning and algorithmic structure.

---

## Mathematical Background

A **Latin square of order n** is an n×n grid filled with symbols {1, …, n} such that:

* each symbol appears **exactly once in every row**
* each symbol appears **exactly once in every column**

This project uses the classical cyclic construction:

> ( L(i, j) = t[(i + j) \bmod n] )

where `t` is a permutation of {1, …, n}.

By varying the permutation `t` and applying row permutations, the program generates multiple Latin squares of the same order.

---

## What the Program Does

For a given input dimension `n`, the program:

1. Generates all permutations of the set {1, …, n}
2. Builds a base Latin square from each permutation
3. Produces additional Latin squares by permuting rows
4. Prints the resulting Latin squares to standard output

All operations are **valid for any n ≥ 1**, within the limits imposed by fixed array sizes.

---

## Key Characteristics

* Language: **C (procedural)**
* No external libraries
* Manual permutation logic (factorial-based enumeration)
* Emphasis on algorithmic transparency rather than optimization
* Fixed-size internal matrices (maximum size 10×10)

---

## Design Notes

* The code intentionally avoids object-oriented abstractions
* The permutation logic (`Tour`, `Permut`, factorial decomposition) is implemented manually
* The focus is on **combinatorial structure**, not performance or memory safety

This makes the project suitable for:

* studying Latin squares
* understanding permutation-based generation
* educational exploration of combinatorics in C

---

## Limitations

* Maximum supported order is limited by static array sizes (10×10)
* No filtering of isomorphic Latin squares
* No additional constraints beyond the Latin square definition

---

## Motivation

This project was created as a **mathematical and algorithmic experiment**, prior to learning object-oriented programming. It represents an early attempt to bridge combinatorics and algorithm design using low-level constructs.

The code is kept close to its original form to preserve this exploratory intent.

---

## Compilation and Execution

```bash
gcc carre.c -o carre
./carre
```

You will be prompted to enter the desired dimension `n`.

---

## License

This project is shared for educational and exploratory purposes.
