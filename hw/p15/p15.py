def count_ways(height, max_steps):
    if height <= 1:
        return 1
    ways = 0
    for i in range(1, min(height, max_steps) + 1):
        ways += count_ways(height - i, max_steps)
    return ways


height = int(input())
max_steps = int(input())
print(count_ways(height, max_steps))  # Output: 5
