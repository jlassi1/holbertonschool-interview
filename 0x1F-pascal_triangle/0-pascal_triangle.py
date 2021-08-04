#!/usr/bin/python3
"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """that returns a list of lists of integers
    representing the Pascal’s triangle of n"""
    if n <= 0:
        return []
    if n == 1:
        return [1]
    res = [[1], [1, 1]]
    if n == 2:
        return res
    for i in range(2, n):
        row = [1]
        for j in range(1, i):
            x = res[i-1][j] + res[i-1][j-1]
            row.append(x)
        row.append(1)
        res.append(row)

    return res
