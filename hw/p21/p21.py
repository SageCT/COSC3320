def solve_for_digits(symbols, s1, s2, s3):
    # Create a set of all symbols
    symbol_set = set(symbols)
    # Create a dictionary to store the assignments of digits to symbols
    assignments = {}
    # Create a list to store the digits in order
    digits = []

    # Define a recursive function to search for the assignments
    def backtrack(index):
        # If all symbols have been assigned, check if the sum is correct
        if index == len(symbols):
            if sum_digits(s1, assignments) + sum_digits(s2, assignments) == sum_digits(
                s3, assignments
            ):
                # If the sum is correct, add the digits to the list in order
                for symbol in symbols:
                    digits.append(assignments[symbol])
                return True
            else:
                return False
        # Otherwise, try assigning each digit to the current symbol
        for digit in range(10):
            if digit not in assignments.values() and (digit != 0 or index != 0):
                assignments[symbols[index]] = digit
                if backtrack(index + 1):
                    return True
                del assignments[symbols[index]]
        return False

    # Define a helper function to sum the digits of a string using the assignments
    def sum_digits(s, assignments):
        return int("".join(str(assignments[c]) for c in s))

    # Call the backtrack function to search for the assignments
    backtrack(0)

    # Return the digits as a string
    return "".join(str(d) for d in digits)


symbols, s1, s2, s3 = input(), input(), input(), input()
print(symbols, s1, s2, s3)
print(solve_for_digits(symbols, s1, s2, s3))
