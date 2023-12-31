Solving For Digits
Backtracking

Suppose we consider two numbers, plus their sum, and replace all occurences of each digit by a symbol:

Example: 054 + 450 = 0504 can be written as ABC + CBA = ABAC where A = 0, B = 5, and C = 4.

We furthermore specify that all symbols are distinct; a given digit is associated with a unique symbol.

Given a list of symbols, and three strings of these symbols, find the unique set of assignments of digits to the symbols such that the first two strings sum to the third string, using a backtracking search (you may assume all test cases only admit one possible set of assignments where all symbols are distinct) The assignments are to be outputted by placing the digits in order, corresponding to the list of symbols.

Example:

Input:
ABC
ABC
CBA
ABAC
Output:
054
This is the example above.

Input:
ABCDEFGHI
ICEBD
HEGDA
CDIAFH
Output:
231760598
Here, the assignments A = 2, B = 3, C = 1, D = 7, E = 6, F = 0, G = 5, H = 9, and I = 8 leads to 81637 + 96572 = 178209, which corresponds to the input CDIAFH. Therefore, given the symbols ABCDEFGHI, we replace the symbols with their assignments and return 231760598
