#!/usr/bin/python3
"""
    Script that determines if a given data set represents a valid UTF-8
    encoding.
"""


def validUTF8(data):
    """
        Determines if a given data set represents a valid UTF-8 encoding.

        Args:
            data: A list of integers representing a byte sequence

        Returns:
            True if the data is a valid UTF-8 encoding, False otherwise
    """

    remaining_byte_count = 0

    for datum in data:
        # Check utf-8 first Byte header
        if remaining_byte_count == 0:
            # Check One Byte
            if datum >> 7 == 0b0:
                continue
            # Check Two Byte
            if datum >> 5 == 0b110 or datum >> 5 == 0b1110:
                remaining_byte_count = 1
            # Check Three Bytes
            elif datum >> 4 == 0b1110:
                remaining_byte_count = 2
            # Check Four Bytes
            elif datum >> 3 == 0b11110:
                remaining_byte_count = 3
            # Check if more than 4 Bytes
            else:
                return False
        # Other bytes
        else:
            # Check utf-8 other Byte header
            if datum >> 6 != 0b10:
                return False
            remaining_byte_count -= 1

    # Check if all bytes were used
    return remaining_byte_count == 0
