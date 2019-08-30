# author - sonaspy@outlook.com
# coding - utf_8
import re
n = eval(input())
count = 0
oldest = 99999999
youngest = 0
young, old = '', ''
for i in range(0, n):
    name_ymd = re.split('[ /]', input())
    name = name_ymd[0]
    ymd = int(''.join(name_ymd[1:]))
    if ymd > 20140906 or 20140906 - ymd > 2000000:
        continue
    count += 1
    if ymd > youngest:
        youngest = ymd
        young = name
    if ymd < oldest:
        oldest = ymd
        old = name
if count == 0:
    print(0)
else:
    print("{} {} {}".format(count, old, young))
