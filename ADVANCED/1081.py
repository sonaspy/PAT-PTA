# author - newguo@sonaspy.cn 
# coding - utf_8 
from fractions import Fraction
n = int(input())
l = input().split()
res = Fraction("0")
for i in l:
    res += Fraction(i)
nu = res.numerator
de = res.denominator
intn = nu // de
res -= Fraction(intn)
if intn != 0 and res != Fraction(0):
    print("{0} {1}".format(intn, res))
elif intn != 0 and res == Fraction(0):
    print(intn)
else:
    print(res)