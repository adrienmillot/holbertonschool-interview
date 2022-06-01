#!/usr/bin/python3
"""
    Script to count the number of lines treated for each status code
    in a log file.
"""

import sys
import re
import signal


class LogParser:
    """
        LogParser class.

        Attributes:
            line_counter: line counter
            status_code_counter: counter for each status code
            global_file_size: global file size treated
    """

    status_code_counter = {
        "200": 0, "301": 0, "400": 0, "401": 0,
        "403": 0, "404": 0, "405": 0, "500": 0
    }
    global_file_size = 0
    line_counter = 0

    def fetch_data(self, line):
        """
            Fetch data from a line.

            Args:
                line: line to parse

            Returns:
                status_code: status code of the log line
                file_size: file size of the log line
        """

        pattern = r'^.*([0-9]{3}) ([0-9]*)$'

        matches = re.search(
            pattern,
            line
        )

        return matches.groups()

    def display_data(self):
        """
            Display data.
        """

        # Print global file size managed
        print("File size: {}".format(self.global_file_size))

        # Print status code counter for each status code
        for status_code, count in sorted(self.status_code_counter.items()):
            print("{}: {}".format(status_code, count))

    def signal_handler(self, signum, frame):
        """
            Signal handler.

            Args:
                signum: signal number
                frame: frame
        """

        self.display_data()
        exit(1)

    def run(self, line):
        """
            Run the parser.
        """

        status_code, file_size = self.fetch_data(line)

        if status_code in self.status_code_counter:
            self.status_code_counter[status_code] += 1

        self.global_file_size += int(file_size)

        if self.line_counter % 10 == 0 and self.line_counter != 0:
            self.display_data()

        self.line_counter += 1

    def signal_handler(self):
        """
            Signal handler.

            Args:
                signum: signal number
                frame: frame
        """

        self.display_data()
        exit(1)


if __name__ == '__main__':
    parser = LogParser()

    try:
        for line in sys.stdin:
            try:
                parser.run(line)
            except Exception:
                pass
    except KeyboardInterrupt:
        parser.display_data()
        raise
    parser.display_data()
