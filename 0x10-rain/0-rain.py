#!/usr/bin/python3
"""
0_rain
"""


def rain(walls):
    """function that calculate how much water will be retained after it rains."""
    if walls == [] or len(walls) == 0:
        return 0
    water = sum(walls[:-1])
    return water