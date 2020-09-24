#!/usr/bin/python3
"""
    Prototype: def validUTF8(data)
    Return: True if data is a valid UTF-8 encoding,
	else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you
	only need to handle the 8 least significant bits
	of each integer
"""

def validUTF8(data):
    """ 0. UTF-8 Validation"""
    try:
        isvalid = True
        for i in data:
            i = i & 0xff
            if i >= 192 and i < 224:
                isvalid = False
            if i >= 224 and i < 240:
                isvalid = False
            if i >= 240 and i < 248:
                isvalid = False
            if i >= 128 and i < 192:
                isvalid = False
            if i > 255:
                isvalid = False
        return(isvalid)
    except Exception as e:
        return(False)
