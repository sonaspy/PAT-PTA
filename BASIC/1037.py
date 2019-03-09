# author -  newguo@sonaspy.cn
# coding - utf_8
p, a = input().split()
p = list(map(int, p.split('.')))
a = list(map(int, a.split('.')))
ans = [''] * 3
if p[0] > a[0]:
    p, a = a, p
    print('-', end='')
if a[2] < p[2]:
    a[1] -= 1
    ans[2] = str(a[2]+29-p[2])
else:
    ans[2] = str(a[2]-p[2])
if a[1] < p[1]:
    a[0] -= 1
    ans[1] = str(a[1]+17-p[1])
else:
    ans[1] = str(a[1]-p[1])
ans[0] = str(a[0]-p[0])
print('.'.join(ans))
