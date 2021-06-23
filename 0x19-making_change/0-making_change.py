#!/usr/bin/python3
"""
Change comes from within
"""


def makeChange(coins, total):
    """ Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total"""
    if (total <= 0):
        return 0
    coins.sort(reverse=True)
    remain = 0
    i = 0
    y = total
    x = 0
    while y >= 0 and i < len(coins):
        try:
            if y / coins[i] >= 1:
                remain += y // coins[i]
                # x.append(y*remain//coins[i])
                y = y % coins[i]
            else:
                i += 1
        except Exception:
            return -1
    # if sum(x) != total:
    #     return (-1)
    if y != 0:
        return (-1)
    return remain
