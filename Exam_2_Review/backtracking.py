from typing import List

# Question number 1

# N-Queens is a problem where you have to make an n x n chess board
# and have queens where they cannot attack each other.

# To Solve: Each queen has to have its own row and be in its own column
# Otherwise, you'd have attacking queens. They also have to be outside
# The diagonal!


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # (r+c) for positive diagonal
        # (r-c) for negative diagonal
        cols, posDiag, negDiag = set(), set(), set()

        res = []
        board = [["."] * n for i in range(n)]

        def backtrack(r):
            # If we reach the end of the row
            if r == n:
                copy = ["".join(row) for row in board]
                res.append(copy)
                return

            # For each column, check if the position is valid (not conflicting with anything)
            for c in range(n):
                if c in cols or (r + c) in posDiag or (r - c) in negDiag:
                    continue
                # If not conflicting with anything then we can add the position
                # to cols, posDiag, and negDiag, and alter the board as well
                cols.add(c)
                posDiag.add(r + c)
                negDiag.add(r - c)
                board[r][c] = "Q"

                # Test the next position (row)
                backtrack(r + 1)

                # If the backtracking iteration done previously finishes, try a different branch
                # To try a different branch first you need to remove the old branch that's already been tried from the result
                cols.remove(c)
                posDiag.remove(r + c)
                negDiag.remove(r - c)
                board[r][c] = "."

        backtrack(0)
        return res

    # Question 2

    # Given an array of integers nums and an integer k,
    # return the total number of continuous subarrays whose sum equals to k

    def subarraySum(self, nums: List[int], k: int) -> int:
        pass
