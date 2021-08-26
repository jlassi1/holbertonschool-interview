#!/usr/bin/python3
"""0. Prime Game """


def is_prime(a):
    return all(a % i for i in range(2, a))


def isWinner(x, nums):
    """function that determine who the winner of each game"""
    if x <= 0 or nums == [] or not nums:
        return None
    r = min(x, len(nums))
    winner = {'Maria': 0, 'Ben': 0}
    i = 0
    while(r != 0):
        for i in nums:
            w = 'Maria'
            if i == 1:
                w = 'Ben'
                winner[w] += 1
            else:
                for j in range(2, i + 1):
                    if is_prime(j):
                        # print(j)
                        w = 'Maria' if w == 'Ben' else 'Ben'
                winner[w] += 1
            # print('-------------------------------------------')
            r -= 1
    # print(winner)
    try:
        return max(winner, key=winner.get)
    except BaseException:
        return None
