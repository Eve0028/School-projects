# Solve a system of linear algebraic equations of the form: "Ax = b" (where x is the unknown) - the method of decomposition into triangular-diagonal factors (LDU).

## Sample usage
Input:
```
Data is loaded from a file in the following order:
1. Square matrix order
2. Square matrix A
3. Vector b

Enter the name of an existing file to read (e.g. data.txt):
data.txt
```
data.txt:
```
4
2 4 3 5
-4 -7 -5 -8
6 8 2 9
4 9 -2 14
2 3 2 3
```

Result:
```
Matrix L:
1.000000 0.000000 0.000000 0.000000
-2.000000 1.000000 0.000000 0.000000
3.000000 -4.000000 1.000000 0.000000
2.000000 1.000000 3.000000 1.000000

Matrix D:
2.000000 0.000000 0.000000 0.000000
0.000000 1.000000 0.000000 0.000000
0.000000 0.000000 -3.000000 0.000000
0.000000 0.000000 0.000000 -4.000000

Matrix U:
1.000000 2.000000 1.500000 2.500000
0.000000 1.000000 1.000000 2.000000
0.000000 0.000000 1.000000 -0.666667
0.000000 0.000000 0.000000 1.000000

Vector y:
2.000000 7.000000 24.000000 -80.000000

Vector z:
1.000000 7.000000 -8.000000 20.000000


********************************************************
Vector x:
19.666667 -38.333333 5.333333 20.000000
********************************************************


Check the calculations over matrices:

Matrix L*D*U - A:
2.000000 4.000000 3.000000 5.000000
-4.000000 -7.000000 -5.000000 -8.000000
6.000000 8.000000 2.000000 9.000000
4.000000 9.000000 -2.000000 14.000000

Result of the equation - vector b:
2.000000 3.000000 2.000000 3.000000
```

