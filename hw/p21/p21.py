def solveForDigits(symbols, first, second, solution):
    def isValid(assignments):
        n1 = int("".join([str(assignments[symbol]) for symbol in first]))
        n2 = int("".join([str(assignments[symbol]) for symbol in second]))
        res = int("".join([str(assignments[symbol]) for symbol in solution]))
        # print("is valid:", n1, n2, res)
        return n1 + n2 == res

    def backtrack(index, assignments):
        if index == len(symbols):
            if isValid(assignments):
                return "".join([str(assignments[symbol]) for symbol in symbols])
            return None

        for digit in range(0, 10):
            if digit not in assignments.values():
                assignments[symbols[index]] = digit
                res = backtrack(index + 1, assignments)
                if res is not None:
                    return res
                assignments[symbols[index]] = None
        return None

    assignments = {c: None for c in symbols}
    return backtrack(0, assignments)


if __name__ == "__main__":
    symbols = [*input()]
    first = [*input()]
    second = [*input()]
    solution = [*input()]

    print(solveForDigits(symbols, first, second, solution))
