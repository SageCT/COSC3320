def lastRemaining(n, leftRight=True):
    # Base case: When n is 1, the last remaining number is 1.
    if n == 1:
        return 1

    if leftRight or n % 2 == 1:  # If odd, add one
        return 2 * lastRemaining(n // 2, not leftRight)

    # If even, subtract one
    else:
        return 2 * lastRemaining(n // 2, not leftRight) - 1


test: int = int(input())
# test = 4

print(lastRemaining(test))
