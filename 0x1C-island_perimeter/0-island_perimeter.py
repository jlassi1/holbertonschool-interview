#!/usr/bin/python3
"""
Island Perimeter
"""


def HelpCount(grid, i, j, row, col):
    # Check border conditions and if
    if i < 0 or j < 0 or j >= col or i >= row or grid[i][j] == 0:
        return 1

    return 0


def island_perimeter(grid):
    """function that returns the perimeter of the island described in grid"""
    perim = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 0:
                continue
            else:
                perim += HelpCount(grid, i + 1, j, len(grid), len(grid[0]))
                perim += HelpCount(grid, i - 1, j, len(grid), len(grid[0]))
                perim += HelpCount(grid, i, j + 1, len(grid), len(grid[0]))
                perim += HelpCount(grid, i, j - 1, len(grid), len(grid[0]))

    return perim
