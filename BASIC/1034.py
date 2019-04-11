# author -  newguo@sonaspy.cn 
# coding - utf_8 

from fractions import Fraction
import re

def solveFractions(frac):
    if abs(frac.numerator) > abs(frac.denominator) and abs(frac.numerator) % abs(frac.denominator) != 0:
        integer = abs(frac.numerator) // frac.denominator
        rf = Fraction(abs(frac.numerator) % frac.denominator, frac.denominator)
        res = str(integer) + ' ' + str(rf)
        if frac.numerator < 0:
            res = '-' + res
    else:
        res = str(frac)
    if frac < 0:
        res = '(' + res + ')'
    return res

list = re.split('[ /]', input())
res, f = ['' for i in range(0, 7)], ['' for i in range(0, 7)]
f[1] = Fraction(int(list[0]), int(list[1]))
f[2] = Fraction(int(list[2]), int(list[3]))
f[3] = f[1] + f[2]
f[4] = f[1] - f[2]
f[5] = f[1] * f[2]
if f[2] == 0:
    res[6] = 'Inf'
else:
    f[6] = f[1]/f[2]
    res[6] = solveFractions(f[6])
for i in range(1, 6):
    res[i] = solveFractions(f[i])
print("{} + {} = {}".format(res[1], res[2], res[3]))
print("{} - {} = {}".format(res[1], res[2], res[4]))
print("{} * {} = {}".format(res[1], res[2], res[5]))
print("{} / {} = {}".format(res[1], res[2], res[6]))