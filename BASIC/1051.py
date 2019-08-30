# author - sonaspy@outlook.com
# coding - utf_8
import math
a = [float(i) for i in input().split()]
x1 = a[0]*math.cos(a[1])
x2 = a[0]*math.sin(a[1])
y1 = a[2]*math.cos(a[3])
y2 = a[2]*math.sin(a[3])
n1 = complex(x1, x2)
n2 = complex(y1, y2)
n = n1*n2
r = n.real
i = n.imag
z1 = '%.2f' % r
z2 = '%.2fi' % i
if -0.005 <= r < 0:
    z1 = '0.00'
if -0.005 <= i < 0:
    z2 = '+0.00i'
if i >= 0:
    z2 = '+' + z2
print(z1 + z2)
