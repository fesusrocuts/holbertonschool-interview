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


i = -1
obj_error = {}
size = 0
try:

    i += 1
    for data in sys.stdin:
        parsed_data = re.split(r'[-+#\s*$ ]', data)
        size_parsed = len(parsed_data)
        if size_parsed > 2:
            i += 1
            size_file = int(parsed_data[size_parsed - 2])
            size += size_file
            error = parsed_data[size_parsed - 3]
            if error in obj_error:
                obj_error[error] += 1
            else:
                obj_error[error] = 1
        if i == 10:
            print("File size: {}".format(size))
            for k, v in sorted(obj_error.items()):
                print("{}: {}".format(k, v))
            i = 0

except Exception as e:
    print("File size: {}".format(size))
    for k, v in sorted(obj_error.items()):
        print("{}: {}".format(k, v))
