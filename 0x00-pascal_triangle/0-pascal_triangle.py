#!/usr/bin/python3
"""
    Returns a list of lists of integers representing the Pascal’s triangle of n
"""


def pascal_triangle(n):
    """
        Return a list of lists representing Pascal's triangle of n rows.
    """

    triangle = []

    for row in range(n):
        triangle.append([1 for column in range(row + 1) if row >= 0])

        if row > 0:
            triangle[row] = [
                triangle[row - 1][column - 1] + triangle[row - 1][column]
                if column != 0 and column != row else triangle[row][column]
                for column in range(row + 1)
                ]

    return triangle
