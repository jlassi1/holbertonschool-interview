#!/usr/bin/python3
"""
Minimum Operations
"""


def minOperations(n):
    """function that calculates the fewest number
    of operations needed to result in exactly
    n H characters in the file"""
    min_op = 0
    if n > 2:
        for i in range(2, n + 1):
            if n % i == 0:
                return minOperations(n // i) + i
    if n == 2:
        min_op = 2
    return min_op
