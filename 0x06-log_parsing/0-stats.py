#!/usr/bin/python3
"""
    Module that parses a log and prints stats to stdout
"""
import re
from sys import stdin

count = 0
global_size = 0
status_codes = {
    "200": 0, "301": 0, "400": 0, "401": 0,
    "403": 0, "404": 0, "405": 0, "500": 0
}


def fetch_data(line):
    """
        Fetch the data
    """

    matches = line.split()

    return matches[-2], matches[-1]


def display_data():
    """
        Display the data
    """
    print("File size: {}".format(global_size))
    for status in sorted(status_codes.keys()):
        if status_codes[status]:
            print("{}: {}".format(status, status_codes[status]))


if __name__ == "__main__":
    try:
        for line in stdin:
            try:
                status_code, file_size = fetch_data(line)
                global_size += int(file_size)
                if status_code in status_codes:
                    status_codes[status_code] += 1
            except:
                pass
            if count == 9:
                display_data()
                count = -1
            count += 1
    except KeyboardInterrupt:
        display_data()
        raise
    display_data()
