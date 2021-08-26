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

    for j ,i in enumerate(nums):
            w = 'Maria'
            if i == 1:
                w = 'Ben'
            else:
                for j in range(3, i + 1):
                    if is_prime(j):
                        w = 'Maria' if w == 'Ben' else 'Ben'
            winner[w] += 1
            if j == r:
                break

    if winner['Ben'] == winner['Maria']:
        return None
    try:
        return max(winner, key=winner.get)
    except Exception:
        return None
