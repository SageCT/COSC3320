Ways to place chess pieces
Dynamic Programming

Given a board with irregular shape, your task is to place chess pieces and make sure no more than 1 chess pieces is placed on the same row or the same column. Output the number of different ways of such placement.

The first line of the input consists of two integers n and k. n means the size of board is nÃ—n and k is the number of chess pieces to be placed. The next n lines describe the shape of the chess board: '#' describes the board region and '.' is the blank region (cannot place chess piece here)

Starter code: pro1.cpp

Example 1

Input:
2 1
.#
#.

Output:
2
Example 2

Input:
3 3
#.#
.##
.##
Output:
2
Example 3

Input:
4 4
...#
..#.
.#..
#...
Output:
1
