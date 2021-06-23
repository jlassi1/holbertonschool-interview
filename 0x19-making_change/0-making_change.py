#!/usr/bin/python3
"""
Change comes from within
"""


def makeChange(coins, total):
    """ Given a pile of coins of different values,
    determine the fewest number of coins needed to meet a given amount total"""
    coins.sort(reverse=True)
    print(coins)
    remains = []
    remain = 0
    i = 0
    y = total
    x = [0]
    while y >= 0 and i < len(coins):
        if y / coins[i] >= 1:
            remain = y // coins[i]
            x.append(y*remain//coins[i])
            y = y % coins[i]
            remains.append(remain)
        else:
            i += 1
    if sum(x) != total:
        return (-1)
    # for i in range(len(remains)):
    #     if x == total:
    #         break
    #     x += remains[i]*coins[i]
    # if x != total:
    #     return (-1)
    return sum(remains)
