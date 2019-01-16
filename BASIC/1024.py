# author - newguo@sonaspy.cn 
# coding - utf_8 
#-1.2E+10
num = input().split('E')
sign = num[0][0]# -
part1 = num[0][1] + num[0][3:] # 12  least 2 bit
part2 = num[1] # +10
x = int(part2) + 1

if int(part2) < 0:
    s = '0' + '.' +'0' *(-x) + part1
else:
    if len(part1) <= x:
        s = part1 + '0'*(x - len(part1))
    elif x < len(part1):
        s = part1[0:x] + '.' +part1[x:]

if sign == '-':
    s = '-' + s
print(s)
    


