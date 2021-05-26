#!/usr/bin/python3
"""
0x16 - Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """Given an n x n 2D matrix, rotate it 90 degrees clockwise."""
    N = len(matrix[0])
    temp = []

    for j in range(N):
        tmp = []
        for i in matrix:
            tmp.append(i[j])
        tmp.reverse()
        temp.append(tmp)

    for i in range(N):
        for j in range(N):
            matrix[i][j] = temp[i][j]
