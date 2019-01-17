# author - newguo@sonaspy.cn
# coding - utf_8
n = eval(input())
l1 = list(map(int, input().split()))
l2 = list(map(int, input().split()))
mp = dict()
for i in range(101):
    mp[i] = 0
for i in l1:
    if i in mp.keys():
        mp[i] += 1
for i in range(1, l2[0]+1):
    if i == l2[0]:
        print(mp[l2[i]], end='')
    else:
        print(mp[l2[i]], end=' ')
