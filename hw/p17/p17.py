def rotationsNeeded(arr, left, right):
    if left == right or arr[left] < arr[right]:
        return left

    mid = (left + right) // 2

    if arr[mid] > arr[mid + 1]:
        return mid + 1

    if arr[mid] >= arr[left]:
        return rotationsNeeded(arr, mid + 1, right)
    else:
        return rotationsNeeded(arr, left, mid)


def search(arr, left, right, target):
    if left > right:
        return -1

    mid = (left + right) // 2

    if arr[mid] == target:
        return mid

    # Check which half of the array the target may be in.
    if arr[left] <= arr[mid]:
        if arr[left] <= target < arr[mid]:
            return search(arr, left, mid - 1, target)
        else:
            return search(arr, mid + 1, right, target)
    else:
        if arr[mid] < target <= arr[right]:
            return search(arr, mid + 1, right, target)
        else:
            return search(arr, left, mid - 1, target)


# Example usage:

arr = input()
arr = [int(x) for x in arr.split()]
target = int(input())
rotations = rotationsNeeded(arr, 0, len(arr) - 1)
found = search(arr, 0, len(arr) - 1, target)
print(rotations)
print(found)
