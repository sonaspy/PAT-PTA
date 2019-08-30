# author - sonaspy@outlook.com
# coding - utf_8
from fractions import *
l = input().split()
deno = int(l[2])
li = list(map(int, str(l[0]).split('/') + str(l[1]).split('/')))
f1 = Fraction(li[0], li[1])
f2 = Fraction(li[2], li[3])
if f2 < f1:
    f1, f2 = f2, f1
first = True
for i in range(0, deno+1):
    frac = Fraction(i, deno)
    if f1 < frac < f2 and frac.denominator == deno:
        if first == True:
            print(frac, end='')
            first = False
        else:
            print(" {}".format(frac), end='')
