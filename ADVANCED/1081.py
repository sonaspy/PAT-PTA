# author -sonaspy@outlook.com
# coding - utf_8
from fractions import Fraction
n = int(input())
l = input().split()
res = Fraction(0)
for i in l:
    res += Fraction(i)
intpart = res.numerator // res.denominator
res -= Fraction(intpart)
if intpart != 0 and res != Fraction(0):
    print("{} {}".format(intpart, res))
elif intpart != 0 and res == Fraction(0):
    print(intpart)
else:
    print(res)
