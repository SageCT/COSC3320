Backtracking Algorithm for Maximum Possible Integer Through Digit Swaps
Consider a positive number, denoted as M. For instance, if M = 385, by swapping the first digit (3) with the second digit (8), we obtain a larger number M' = 835. Further, by swapping the second and third digits of M', we get M" = 853, which is the largest number that can be formed using the digits of M.

Questions

A) Provide a Backtracking Algorithm that for given two positive numbers, M and K, determine the highest possible number that can be obtained by performing at most K swap operations on the digits of M.

B) Provide a Backtracking Algorithm that for a given positive integer M, identify the minimum number of swaps, represented as K required to produce the maximum possible number using the digits of M.

Examples

Input:
129845
3
Output:
985241
4
Input:
129814999
2
Output:
999814921
4
