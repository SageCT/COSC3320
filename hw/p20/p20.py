def is_stepping_number(num):
    num_str = str(num)
    for i in range(1, len(num_str)):
        if abs(int(num_str[i]) - int(num_str[i - 1])) != 1:
            return False
    return True


def generate_stepping_numbers(low, high):
    def backtrack(num):
        if low <= num <= high:
            stepping_numbers.append(num)
        if num == 0 or num > high:
            return
        last_digit = num % 10
        if last_digit + 1 <= 9:
            backtrack(num * 10 + last_digit + 1)
        if last_digit - 1 >= 0:
            backtrack(num * 10 + last_digit - 1)

    stepping_numbers = []
    for i in range(10):
        backtrack(i)

    return sorted(stepping_numbers)


# Read input
low = int(input())
high = int(input())
stepping_numbers = generate_stepping_numbers(low, high)
print(" ".join(map(str, stepping_numbers)))
