#!/usr/bin/python3
"""
0_rain
"""


def rain(walls):
    """function that calculate how much water
    will be retained after it rains."""
    if walls == [] or len(walls) == 0:
        return 0
    water = 0
    n = len(walls)

    left_wall = [0 for _ in range(n)]
    right_wall = [0 for _ in range(n)]
    left_wall[0] = walls[0]
    right_wall[n - 1] = walls[n - 1]

    for i in range(1, n):
        left_wall[i] = max(left_wall[i - 1], walls[i])
    # print(left_wall)
    for i in range(n - 2, -1, -1):
        right_wall[i] = max(right_wall[i + 1], walls[i])
    # print(right_wall)
    # print(walls)
    for i in range(n):
        water += min(left_wall[i], right_wall[i]) - walls[i]
    return water
