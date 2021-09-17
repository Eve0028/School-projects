# Calculate formulas using the Taylor series.

## Sample usage
Input:
```
List of formulas:
0. (1 - x)^(1/3)
1. (1 + x)^(-3/2)
2. ln(x)

Enter number of formula:
1

Enter start of the range:
-0.34

Enter end of the range:
0.503

Enter a number of sub-ranges (an integer):
10

Enter a precision of the result:
0.0001
```

Result:
```
x		taylor_series(x)	(1 + x)^(-3/2)		number of words		stop condition
-------------------------------------------------------------------------------------------------------------------
 -0.34		1.8649806		  1.8650226			10			0
 -0.26		1.5572369		  1.5573204			7			0
 -0.17		1.3257230		  1.3258140			5			0
 -0.09		1.1464616		  1.1464766			4			0
 -0.00		1.0042000		  1.0042147			1			0
  0.08		0.8890200		  0.8891197			3			0
  0.17		0.7943934		  0.7944452			5			0
  0.25		0.7154155		  0.7154559			7			0
  0.33		0.6486925		  0.6487404			9			0
  0.42		0.5917038		  0.5917853			11			0
  0.50		0.5428006		  0.5427021			14			0
 -------------------------------------------------------------------------------------------------------------------
```
Conditions:<br>
0 - result has reached required precision,<br>
1 - maximum number of calculated words of the series (declared in the program) has been reached,<br>
2 - both at once.
