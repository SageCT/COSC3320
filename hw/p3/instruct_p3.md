Minimum Maximum Sum
Backtracking

We are given an integer array numbers where numbers[i] is the i-th number. We assign the n numbers to k groups. Each number is assigned to exactly one group. Find the assignment such that the maximum sum of the groups is minimized.

Return the minimum maximum sum.

The input consists of two lines; the second line is the numbers array; the first line has the length of the numbers array n and number of groupsk. Output should be a single number that is the minimum maximum sum among the groups.

Example 1

Input:
3 3
3 2 3
Output:
3
Explanation:
Assigning each number to each worker leads to maximum sum 3.
No other assignment can have lower maximum sum.
Example 2

Input:
5 2
1 2 4 7 8
Output:
11
Explanation:
Assignment: group 1: 1,2,8, sum: 11
group 2: 4,7, sum: 11
No other assignments can be lower maximum sum.
