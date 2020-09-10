#!/usr/bin/python3
""" Write a script that reads stdin line by line and
computes metrics
Input format: <IP Address> - [<date>]
"GET /projects/260 HTTP/1.1"
<status code> <file size>
After every 10 lines and/or a keyboard interruption (CTRL + C),
print these statistics from the beginning:
Total file size: File size: <total size>
where <total size> is the sum of all previous <file size>
(see input format above)
Number of lines by status code:
possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
if a status code doesn’t appear, don’t print anything
for this status code
format: <status code>: <number>
status codes should be printed in ascending order
"""
import re
import sys


def print_sorted_dict(status_codes):
    """
    status_code have all data args with codes and times
    """
    sorted_keys = sorted(status_codes.keys())
    print('\n'.join(["{:d}: {:d}".format(k, status_codes[k])
                     for k in sorted_keys if status_codes[k] != 0]))


def __run():
    try:
        total = 0
        status_codes = \
            {code: 0 for code in [200, 301, 400, 401, 403, 404, 405, 500]}
        for i, rawline in enumerate(sys.stdin, 1):
            words = rawline.split()
            total += int(words[-1])
            status_codes[int(words[-2])] += 1
            if i % 10 == 0:
                print("File size: {:d}".format(total))
                print_sorted_dict(status_codes)
    finally:
        print("File size: {:d}".format(total))
        print_sorted_dict(status_codes)


if __name__ == "__main__":
    __run()
