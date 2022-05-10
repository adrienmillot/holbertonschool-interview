#!/usr/bin/python3
"""
    Min # of operations to reach n char
"""


def minOperations(n):
    """
        Min # of operations to reach n char

        Args:
            n (int): number of chars

        Returns:
            int: min # of operations
    """

    nb_caracter = 0
    nb_operations = 0
    next_operation = 2

    if type(n) is not int or n <= nb_caracter:
        return 0

    while next_operation <= n:
        if n % next_operation == 0:
            nb_operations += next_operation
            n /= next_operation
        else:
            next_operation += 1

    return nb_operations
