# author -  newguo@sonaspy.cn
# coding - utf_8

from fractions import Fraction
import re


def solveFractions(frac):
    integer = int(frac.numerator / frac.denominator)
    rf = abs(frac - integer)
    if abs(integer) > 0 and rf != 0:
        res = str(integer) + ' ' + str(rf)
    else:
        res = str(frac)
    if frac < 0:
        res = '(' + res + ')'
    return res

fs = input().split()
res , strout = [], []
f1, f2 = Fraction(fs[0]), Fraction(fs[1])
strout.append(solveFractions(f1))
strout.append(solveFractions(f2))
res.append(f1 + f2)
res.append(f1 - f2)
res.append(f1 * f2)
for i in range(3):
    strout.append(solveFractions(res[i]))
if f2 == 0:
    strout.append('Inf')
else:
    strout.append(solveFractions(f1 / f2))
print("{} + {} = {}".format(strout[0], strout[1], strout[2]))
print("{} - {} = {}".format(strout[0], strout[1], strout[3]))
print("{} * {} = {}".format(strout[0], strout[1], strout[4]))
print("{} / {} = {}".format(strout[0], strout[1], strout[5]))
