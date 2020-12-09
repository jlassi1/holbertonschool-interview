#!/usr/bin/python3
"""   Lockboxes   """
import numpy as np


def canUnlockAll(boxes):
    """Determine if all the boxes can be opened"""

    if boxes[0] == [] or not isinstance(boxes, list):
        return False
    keys_list = [0]
    for boxe in range(len(boxes)):
        for key in boxes[boxe]:
            if keys_list.count(key) < 1 and key != boxe:
                keys_list.append(key)
    if len(keys_list) == len(boxes):
        return True
    return False
