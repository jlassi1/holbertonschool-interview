#!/usr/bin/python3
"""
UTF-8 Validation
"""


def validUTF8(data):
    """
    function that determines if a given data
    set represents a valid UTF-8 encoding
    """
    try:
        bytes([i & ((2**8)-1) for i in data]).decode("UTF-8")
        return True
    except Exception:
        return False
