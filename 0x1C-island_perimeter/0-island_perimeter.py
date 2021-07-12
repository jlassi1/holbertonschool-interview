#!/usr/bin/python3
"""
Island Perimeter
"""


def island_perimeter(grid):
    """function that returns the perimeter of the island described in grid"""
    perim = 0
    for i in range(len(grid)-1):
        for j in range(len(grid[0])-1):
            if grid[i][j] == 0:
                continue
            else:
                if grid[i][j-1] == 0:
                    perim += 1
                if grid[i][j + 1] == 0:
                    perim += 1
                if grid[i+1][j] == 0:
                    perim += 1
                if grid[i-1][j] == 0:
                    perim += 1

    return perim
