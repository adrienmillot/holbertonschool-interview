#!/usr/bin/python3
"""
    Chess module.
"""

import sys


class Chess:
    """
        Chess class.

        Attributes:
            __size: Board size
            __board: matrix defines the chess board
    """
    __size = 0
    __board = []

    def __init__(self, prmSize):
        """
            Constructor

            Args:
                prmSize: Board size
        """

        self.size = prmSize
        self._init_matrix()

    @property
    def size(self):
        """
            Size getter
        """

        return self.__size

    @size.setter
    def size(self, prmValue):
        """
            Size setter

            Args:
                prmValue: size value
        """

        if isinstance(prmValue, str) and prmValue.isnumeric():
            prmValue = int(prmValue)
        if not isinstance(prmValue, int):
            raise TypeError("N must be a number")
        if prmValue < 4:
            raise ValueError("N must be at least 4")

        self.__size = prmValue

    def _init_matrix(self):
        """
            Initialize the chess board
        """

        self.__board = [0 for col in range(self.size)]

    def _is_safe(self, row_index, column_number):
        """
            Checks if position is safe from attack.

            Args:
                row_index: The row to check.
                column_number: The colum to check.

            Return:
                True if it's safe, False otherwise
        """

        for c in range(column_number):
            if (
                self.__board[c] is row_index or
                abs(self.__board[c] - row_index) is abs(c - column_number)
            ):
                return False
        return True

    def check(self, column):
        """
            Checks the board state column by column

            Args:
                col: The current colum to check.
        """

        if column is self.size:
            print(str([[c, self.__board[c]] for c in range(self.size)]))
            return

        for row in range(self.size):
            if self._is_safe(row, column):
                self.__board[column] = row
                self.check(column + 1)


if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        chess = Chess(sys.argv[1])
        chess.check(0)
    except Exception as exception:
        print(exception)
        sys.exit(1)
