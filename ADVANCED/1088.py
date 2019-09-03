# author - sonaspy@outlook.com
# coding - utf_8

from fractions import Fraction

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
res, str_res = [], []
f1, f2 = Fraction(fs[0]), Fraction(fs[1])
str_res.append(solveFractions(f1))
str_res.append(solveFractions(f2))
res.append(f1 + f2)
res.append(f1 - f2)
res.append(f1 * f2)
for i in range(3):
    str_res.append(solveFractions(res[i]))
if f2 == 0:
    str_res.append('Inf')
else:
    str_res.append(solveFractions(f1 / f2))
print("{} + {} = {}".format(str_res[0], str_res[1], str_res[2]))
print("{} - {} = {}".format(str_res[0], str_res[1], str_res[3]))
print("{} * {} = {}".format(str_res[0], str_res[1], str_res[4]))
print("{} / {} = {}".format(str_res[0], str_res[1], str_res[5]))