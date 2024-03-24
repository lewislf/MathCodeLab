# MathCodeLab

**Matrix Algebra Toolkit**

This C program implements a toolkit for basic matrix algebra operations, including addition, subtraction, and multiplication of matrices. The program uses a `tMatrix` structure to represent matrices, with fields for the number of rows and columns, a pointer to a 2D array for the matrix elements, and a flag to indicate if an operation was successful.

### Usage
1. **Compilation:** Compile the program using a C compiler such as GCC:
   ```
   gcc -o matrix_toolkit matrix_toolkit.c
   ```

2. **Execution:** Run the compiled executable to perform matrix operations. The program will prompt you to enter the dimensions and elements of two matrices, and then choose an operation to perform.

### Features
- **Matrix Input:** Reads the dimensions and elements of two matrices from the user.
- **Matrix Operations:** Supports addition, subtraction, and multiplication of matrices.
- **Error Handling:** Checks if matrices have compatible dimensions for operations and sets a flag to indicate success or failure.
- **Memory Management:** Allocates and deallocates memory dynamically for matrices to avoid memory leaks.

### Example
```
Enter the number of rows and columns of Matrix A: 2 2
Enter the elements of Matrix A:
1 2
3 4

Enter the number of rows and columns of Matrix B: 2 2
Enter the elements of Matrix B:
5 6
7 8

Matrices Operations
1) Sum
2) Subtraction
3) Multiplication
Choose an option: 1

Matriz Result:
6 8
10 12
```

This toolkit provides a basic framework for working with matrices in C, but can be expanded with additional features and optimizations as needed.
