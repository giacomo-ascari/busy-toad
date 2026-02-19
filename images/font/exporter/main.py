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

def main():
    print("Hello from exporter!")


if __name__ == "__main__":
    main()
