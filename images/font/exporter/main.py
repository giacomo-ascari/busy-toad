'''
The printable subset of ASCII is used, from char 32 to 127.
The input image is expected as follows:
image_width = char_width * 12
image_height = char_height * 8
E.g.: 10x16 --> 120x128
   0 1 2 3 4 5 6 7 8 9 A B
 +------------------------
0|   ( 0 8 @ H P X ` h p x
1| ! ) 1 9 A I Q Y a i q y
2| " * 2 : B J R Z b j r z
3| # + 3 ; C K S [ c k s {
4| $ , 4 < D L T \\d l t |
5| % - 5 = E M U ] e m u }
6| & . 6 > F N V ^ f n v ~
7| ' / 7 ? G O W _ g o w
Read from up to down, left to right
'''

# unset GTK_PATH
# uv run main.py ../font_mediumshaded_10x14.png 10 14 4

import os
import argparse
from PIL import Image
import math

def getlevel(image, x, y, fd):
    greyscale = 0
    for channel in range(3):
        greyscale += image.getpixel((x,y))[channel]
    greyscale = greyscale // 3
    levels = []
    for i in range(fd):
        levels.append(i * 255 // (fd - 1))
    if greyscale in levels:
        return levels.index(greyscale)
    return 0

def main():
    print("Hello from exporter!")

    parser = argparse.ArgumentParser(prog='font exporter', description='', epilog='')
    parser.add_argument("input", type=str)
    parser.add_argument("font_width", type=int)
    parser.add_argument("font_height", type=int)
    parser.add_argument("depth", type=int)
    args = parser.parse_args()

    print(args.input, args.font_width, args.font_height, args.depth)

    fw = args.font_width
    fh = args.font_height
    fd = args.depth

    horizontal_count = 12
    vertical_count = 8

    bit_depth = int(math.log2(args.depth))

    with Image.open(args.input) as image:
        assert image.width / fw == horizontal_count, "wrong width"
        assert image.height / fh == vertical_count, "wrong height"

        bits_string = ""
        proc = []

        for i in range (horizontal_count):
            for j in range (vertical_count):
                for h in range(fh):
                    for w in range(fw):
                        x = w + i * fw
                        y = h + j * fh
                        level = getlevel(image, x, y, fd)
                        bits_string += "{0:b}".format(level)

        for i in range(len(bits_string) // 8):
            index = i * 8
            proc.append(int(bits_string[index:index+8], 2))
        
        for p in proc:
            print("{0:x}, ".format(p), end="")
        print()


if __name__ == "__main__":
    main()
