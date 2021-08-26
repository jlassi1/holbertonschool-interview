#!/usr/bin/python3
"""0. Prime Game """


def is_prime(a):
    return all(a % i for i in range(2, a))


def isWinner(x, nums):
    """function that determine who the winner of each game"""
    if x < 1 or not nums or nums == []:
        return None
    stop = min(x, len(nums))
    winner = {'Maria': 0, 'Ben': 0}

    for idx, i in enumerate(nums):
        w = 'Maria'
        if i == 1:
            w = 'Ben'
        else:
            for j in range(3, i + 1):
                if is_prime(j):
                    w = 'Maria' if w == 'Ben' else 'Ben'
        winner[w] += 1
        if idx == stop:
            break

    if winner['Ben'] == winner['Maria']:
        return None
    try:
        return max(winner, key=winner.get)
    except Exception:
        return None
