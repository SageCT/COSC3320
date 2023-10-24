# P1 on Exam


def findMaxDiff(A, left, right):
    if left == right:
        return 0

    mid = (left + right) // 2

    # Recursively find the maximum differences in the left and right subarrays
    left_max_diff = findMaxDiff(A, left, mid)
    right_max_diff = findMaxDiff(A, mid + 1, right)

    # Calculate the maximum and minimum values in the left and right subtrees
    left_min = min(A[left : mid + 1])
    right_max = max(A[mid + 1 : right + 1])

    across_max_diff = right_max - left_min

    return max(left_max_diff, right_max_diff, across_max_diff)


# A = [4, 3, 10, 2, 9, 1]
# n = len(A)
# max_diff = findMaxDiff(A, 0, n - 1)
# print("The maximum difference is:", max_diff)

# P2 on Exam


def maxScore(i, j, A, memo={}):
    if (i, j) in memo:
        return memo[(i, j)]
    if i >= len(A) or j >= len(A[0]) or j < 0 or i < 0:
        return 0

    moveDown = A[i][j] + maxScore(i + 1, j, A)
    moveRight = A[i][j] + maxScore(i, j + 1, A)

    memo[(i, j)] = max(moveDown, moveRight)
    return memo[(i, j)]


# Example usage:
A = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
B = [
    [-1, 7, -8, 10, -5],
    [-4, -9, 8, -6, 0],
    [5, -2, -6, -6, 7],
    [-7, 4, 7, -3, -3],
    [7, 1, -6, 4, -9],
]
maximum_score = maxScore(0, 0, B)
print("Maximum score:", maximum_score)


# P3 on Exam


def permutations(nums):
    def dfs(nums, path, res, used):
        if len(path) == len(nums):
            res.append(path[:])
            return
        for i in range(len(nums)):
            if used[i] or (i > 0 and nums[i] == nums[i - 1] and not used[i - 1]):
                continue
            used[i] = True
            path.append(nums[i])
            dfs(nums, path, res, used)
            used[i] = False
            path.pop()

    res = []
    used = [False] * len(nums)
    nums.sort()
    dfs(nums, [], res, used)
    return res


# Example Usage
# A = [3, 2, 3]
# print("Permutations: ", permutations(A))

# P4 on exam


def is_balanced(string):
    n = len(string)

    # Initialize a 2D DP table to keep track of open brackets and parentheses
    dp = [[0, 0] for _ in range(n + 1)]

    for i in range(1, n + 1):
        if string[i - 1] in "([":
            dp[i][0] = dp[i - 1][0] + 1
            dp[i][1] = dp[i - 1][1]
        elif string[i - 1] in ")]":
            dp[i][1] = dp[i - 1][1] + 1
            dp[i][0] = dp[i - 1][0]

    # The string is balanced if and only if the counts of open and close brackets match
    return dp[n][0] == dp[n][1]


# Test the function with an example
# example_string = "([()][]())[()()]()"
# result = is_balanced(example_string)
# if result:
#     print("The string is balanced.")
# else:
#     print("The string is not balanced.")
