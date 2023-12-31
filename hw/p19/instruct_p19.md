Random Number Game
Two players, Robert and Rachel, play a game with random numbers. On each round, Robert and Rachel each choose a random positive integer. They then earn points, equal to the number of integers chosen by the other player in previous rounds, which are less than their chosen integer. Players earn no points in the first round.

Develop an efficient divide-and-conquer algorithm for computing the final scores of the game for Robert and Rachel, given the series of numbers chosen by each player in each round. A runtime complexity of O(n log n) will be possible.

Hint: Use mergesort as a base for your algorithm. The fact that the subarrays of games under consideration are sorted will help you to efficiently count game wins.

Example

Example of play with a game of four rounds:
Round 1: Robert chooses 5, Rachel chooses 7.
Round 2: Robert chooses 3, Rachel chooses 5. Neither player earns points, as Rachel's 5 is equal to Robert's 5 from round 1, while Robert's 3 is less than Rachel's 7.
Round 3: Robert chooses 6, Rachel chooses 8. Rachel gets 2 points, for besting Robert's 5 and 3. Robert gets 1 point for besting Rachel's 5
Round 4: Robert chooses 9, Rachel chooses 4. Robert gets 3 points as his 9 bests Rachel's 7, 5, and 8. Rachel gets one point for besting Robert's 3.

The total points for Robert is 4, and for Rachel, is 3.

The input format for this problem is:

first line is Robert's chosen numbers, separated by spaces

second line is Rachel's chosen numbers, separated by spaces

The output expected is a single line, with Robert's final score first, followed by Rachel's.

Input:
5 3 6 9
7 5 8 4
Output:
4 3

This is the example game described above.
