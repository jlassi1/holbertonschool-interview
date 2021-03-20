#!/usr/bin/python3
"""0. N queens """
import sys


def under_attack(col, queens):
    return col in queens or \
        any(abs(col - x) == len(queens) - i for i, x in enumerate(queens))


def solve(n):
    solutions = [[]]
    for row in range(n):
        solutions = [solution + [i + 1]
                     for solution in solutions
                     for i in range(BOARD_SIZE)
                     if not under_attack(i + 1, solution)]
    return solutions


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if sys.argv[1].isnumeric():
        N = int(sys.argv[1])
    else:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)
    BOARD_SIZE = N
    for answer in solve(BOARD_SIZE):
        print(list(enumerate(answer, start=1)))
