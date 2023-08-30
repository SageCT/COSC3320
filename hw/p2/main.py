from typing import List


def highest_return(arr):
    if len(arr) <= 1:
        return 0

    mid = len(arr) // 2
    left_max = highest_return(arr[:mid])
    right_max = highest_return(arr[mid:])
    max_crossing = max(arr[mid:]) - min(arr[:mid])

    return max(left_max, right_max, max_crossing)


def main():
    n = int(input())
    arr = list(map(int, input().split()))
    result = highest_return(arr)
    print(max(result, 0))


main()
