import math

def solve_single_case(n, b, c):
    if n == 1:
        return 0 if c == 0 else 1

    max_valid = n - 1
    last_element = b * (n - 1) + c

    if b == 1 and c == 0:
        return 0

    if b == 0:
        if n == 1:
            return 0 if c == 0 else 1
        if c >= n:
            return n
        if n > 2 and c < n - 1:
            return -1
        if n == 2:
            if c == 1 or c == 0:
                return 1
            return 2
        return -1

    if b > n:
        return -1
    if c > max_valid and b > 0:
        return n
    if last_element < max_valid:
        return -1

    if b > 0:
        oversized_start = max(0, (max_valid - c) // b + 1)
        operations = n - oversized_start

        if operations < n and b > 1:
            return -1
        return operations

    if b < 0:
        if c > max_valid or last_element > max_valid:
            return -1
        if c < 0 or last_element < 0:
            return -1

        operations = 0
        for i in range(n):
            if b * i + c > max_valid:
                operations += 1

        if operations < n and abs(b) > 1:
            return -1
        return operations

    return -1

def main():
    t = int(input())

    for _ in range(t):
        n, b, c = map(int, input().split())
        result = solve_single_case(n, b, c)
        print(result)

main()