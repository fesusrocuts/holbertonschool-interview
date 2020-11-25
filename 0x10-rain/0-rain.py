#!/usr/bin/python3
"""
0. Rain mandatory

Given a list of non-negative integers representing walls of width 1,
calculate how much water will be retained after it rains.
"""


def rain(walls):
    """
    0. Rain mandatory

    Given a list of non-negative integers representing walls of width 1,
    calculate how much water will be retained after it rains.
    """
    if (len(walls) < 2):
        return 0
    return (sum(walls[1:-1]))
