# author - sonaspy@outlook.com
# coding - utf_8
n = eval(input())
arr = list()
mp1 = dict()
mp2 = dict()
mp1['C'] = 0
mp1['B'] = 0
mp1['J'] = 0
mp2['C'] = 0
mp2['B'] = 0
mp2['J'] = 0
p1w, p1t, p1l, p2w, p2t, p2l = 0, 0, 0, 0, 0, 0
for i in range(0, n):
    c1, c2 = input().split()
    if c1 == c2:
        p1t += 1
        p2t += 1
    elif c1 == 'C' and c2 == 'B':
        p2w += 1
        p1l += 1
        mp2['B'] += 1
    elif c1 == 'C' and c2 == 'J':
        p1w += 1
        p2l += 1
        mp1['C'] += 1
    elif c1 == 'B' and c2 == 'J':
        p2w += 1
        p1l += 1
        mp2['J'] += 1
    elif c1 == 'B' and c2 == 'C':
        p1w += 1
        p2l += 1
        mp1['B'] += 1
    elif c1 == 'J' and c2 == 'B':
        p1w += 1
        p2l += 1
        mp1['J'] += 1
    elif c1 == 'J' and c2 == 'C':
        p2w += 1
        p1l += 1
        mp1['C'] += 1

print("{} {} {}\n{} {} {}".format(p1w, p1t, p1l, p2w, p2t, p2l))
m1, m2 = 0, 0
c1, c2 = 'B','B'
for k,v in mp1.items():
    if v > m1:
        m1 = v
        c1 = k

for k, v in mp2.items():
    if v > m2:
        m2 = v
        c2 = k
print(c1,c2)
